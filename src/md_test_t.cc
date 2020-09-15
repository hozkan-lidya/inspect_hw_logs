#include "md_test_t.hpp"

// mbo_update_t::mbo_update_t(){

// }
// struct mbo_update_t;
template <uint64_t m>
mbo_update_raw_t::mbo_update_raw_t(std::array<uint64_t, m>& arr) : 
ts                (arr[0]), 
hdr_oid           (arr[1]), 
hdr_obu_type      (arr[2]), 
hdr_symbol        (arr[3]), 
hdr_side          (arr[4]), 
hdr_ready         (arr[5]), 
hdr_valid         (arr[6]), 
pld_quantity      (arr[7]), 
pld_price         (arr[8]), 
pld_ready         (arr[9]),
pld_valid         (arr[10])
// tob_update_price  (arr[11]),  
// tob_update_qty    (arr[12]),  
// tob_update_symbol (arr[13]),  
// tob_update_side   (arr[14]),  
// tob_update_empty  (arr[15]),  
// top_of_book_valid (arr[16]),  
// book_stream_price (arr[17]),  
// book_stream_qty   (arr[18]),  
// book_stream_symbol(arr[19]),  
// book_stream_level (arr[20]),  
// book_stream_side  (arr[21]),  
// book_stream_valid (arr[22]),  
// book_stream_empty (arr[23]),  
// book_stream_end   (arr[24])

{
 // NOP
}
mbo_update_raw_t::~mbo_update_raw_t() {}


mbp_update_t::mbp_update_t(std::array<uint64_t, 11>& arr) : 
ts          (arr[0]), 
oid         (arr[1]), 
qty         (arr[2]), 
price       (arr[3]), 
valid       (arr[4]), 
symbol      (arr[5]), 
side        (arr[6]), 
add_rm      (arr[7]), 
tag_valid   (arr[8]), 
tag         (arr[9]), 
trans_oid   (arr[10])
{
  // NOP
}
mbp_update_t::~mbp_update_t() {}


md_test_t::md_test_t(const log_files_t& log_files) :
_mbo_file_name(log_files.mbo_file_name),
_mbp_file_name(log_files.mbp_file_name) {

  mbo_updates = read_txt_to_vec<mbo_update_raw_t, 11>(_mbo_file_name);
  mbp_updates = read_txt_to_vec<mbp_update_t, 11>(_mbp_file_name);

}


template <typename update_t, int m>
std::vector<update_t> md_test_t::read_txt_to_vec(const string& f_name){
  std::vector <update_t> updates;
  updates.reserve(0xFFFF);
  int k{0};
  bool seek_pld{false};

  std::ifstream in_file(f_name);
  std::string line, ss;

  std::array<uint64_t, m> temp_arr;
    // std::cout<< sizeof(update_t) / sizeof(uint32_t)<<" -- \n";
  
  if constexpr( std::is_same<update_t, mbo_update_raw_t>::value ) {    
    while (getline(in_file, line)) {
      if (line[0] == '='){
        continue;
      }
      std::stringstream ss_line(line);
      ss_line >> ss;
      // std::cout << ss<< "\n ";

      ss_line >> temp_arr[ k++ ];
      if (k ==m){
        k = 0;
        if (temp_arr[6] == 1) {
          updates.emplace_back(temp_arr);
          
          if (temp_arr[2] != 3 ) {  // Seek for pld unless it is a Delete msg.
            seek_pld = true;
          }
          // std::cout<<mm.tob_update_symbol<<"\n";
        } 
        else if (seek_pld && temp_arr[10]) {
          // std::cout<< updates.back()<< " -- ";
          auto & mm = updates.back();
          mm.pld_quantity = temp_arr [7];   // quantity of the payload
          mm.pld_price = temp_arr[8];       // price of the payload
          seek_pld = false;   // restore the flag to false again 
          
          // const auto & mm2 = updates.back();
          // if (mm.pld_price != mm2.pld_price || mm.pld_quantity != mm2.pld_quantity)
          //   {std:: cout << "AHAAA\n";}
          // std::cout<< updates.back()<< "\n";
        }
      }
    }
  }
  else {
    while (getline(in_file, line)) {
      if (line[0] == '='){
        continue;
      }
      std::stringstream ss_line(line);
      ss_line >> ss;
      // std::cout << ss<< "\n ";

      ss_line >> temp_arr[ k++ ];
      if (k ==m){
        k = 0;
        updates.emplace_back(temp_arr);
      }
    }
  }
  return updates;
}


void md_test_t::match_mbo_mbp(match_fn_t match_fn ){
  // match_fn(5);
  auto head_mbp =mbp_updates.begin(); // This one is not going to change
  // auto tail_mbp =mbp_updates.begin();
  // std::vector<mbp_update_t>::iterator tail_mbp{mbp_updates.begin()};
  std::advance(head_mbp, 1);
  std::cout<< "AHAAAA " << *head_mbp <<"\n";
  
  for (const auto& x : mbo_updates){
    while (x.ts > (head_mbp -> ts) ) {
      ++head_mbp;
    };
    // while (x.ts > (tail_mbp -> ts) ) {
    //   ++tail_mbp;
    // };

    // while (!tail_mbp -> tag_valid) {
    //   ++tail_mbp;
    // };

    auto tail_mbp =   mbp_updates.end();

    auto temp = std::find_if(head_mbp, tail_mbp, 
      [=](const mbp_update_t & M){
      bool cond_0 = \ 
        static_cast<bool>(M.valid )                                 &&
        M.oid == static_cast<uint32_t>(x.hdr_oid)                   &&
        M.side    == x.hdr_side                                     &&
        M.symbol  == x.hdr_symbol                                   &&
        static_cast<bool>(M.add_rm) ^ static_cast<bool>(x.hdr_obu_type);

        
        return cond_0;
        } );
    if(temp == mbp_updates.end()){
      std::cout<< "NOT PRESENT"<<"\n";
    }
      
    // std::cout<< "AHAAAA " << std::boolalpha << cond_0<<"\n";
    // std::cout<< "AHAAAA 2 " << *temp<<"\n";
    }

  }
  

void md_test_t::sort_entries() {
std::sort(mbo_updates.begin(), mbo_updates.end(), [](auto &left, auto &right) {
    return left.ts < right.ts;
});
std::sort(mbp_updates.begin(), mbp_updates.end(), [](auto &left, auto &right) {
    return left.ts < right.ts;
});
}


size_t md_test_t::mbo_size(){
  return mbo_updates.size();
}

size_t md_test_t::mbp_size(){
  return mbp_updates.size();
}