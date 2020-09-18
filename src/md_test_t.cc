#include "md_test_t.hpp"

md_test_t::md_test_t(const log_files_t& log_files) :
_mbo_file_name(log_files.mbo_file_name),
_mbp_file_name(log_files.mbp_file_name) {

  mbo_updates = read_txt_to_vec<mbo_update_raw_t, 11>(_mbo_file_name);
  mbp_updates = read_txt_to_vec<mbp_update_t, 11>(_mbp_file_name);
  sort_entries();
}

template <typename update_t, int m>
std::vector<update_t> md_test_t::read_txt_to_vec(const string& f_name){
  std::vector <update_t> updates;
  updates.reserve(0xFFFF);
  int k{0};
  // bool seek_pld{false};

  std::ifstream in_file(f_name);
  // std::string line/*, ss*/;

  std::array<uint64_t, m> temp_arr;
    // std::cout<< sizeof(update_t) / sizeof(uint32_t)<<" -- \n";
  

    while (in_file) {
      // if (line[0] == '='){
      //   continue;
      // }
      // std::stringstream ss_line(line);
      // ss_line >> ss;
      // std::cout << ss<< "\n ";

      in_file >> temp_arr[ k++ ];
      if (k ==m){
        k = 0;
        updates.emplace_back(temp_arr);
      }
    }
  return updates;
}


void md_test_t::match_mbo_mbp(match_fn_t match_fn ){
  match_fn(5);
  auto head_mbp =mbp_updates.begin(); // This one is not going to change
  auto tail_mbp =   mbp_updates.end();
  // auto tail_mbp =mbp_updates.begin();
  // std::vector<mbp_update_t>::iterator tail_mbp{mbp_updates.begin()};
  // std::advance(head_mbp, 1);

  for (const auto & x : mbo_updates_c){
    while (! (x.ts < (head_mbp -> ts)) ) {
      ++head_mbp;
    };

    auto found = std::find_if(head_mbp, 
                             tail_mbp, 
                             [=](const mbp_update_t & M) {
      bool is_match = \
        static_cast<bool>(M.valid)                                                   &&
        M.oid == static_cast<uint32_t>(x.hdr_oid)                                    &&
        M.side    == x.hdr_side                                                      &&
        M.symbol  == x.hdr_symbol                                                    &&
        static_cast<bool>(M.add_rm) ^ static_cast<bool>(x.hdr_obu_type)              &&
        (x.hdr_obu_type != 0 || (M.price == x.pld_price && M.qty == x.pld_quantity)) &&
        (x.hdr_obu_type != 1 || M.qty == x.pld_quantity);
    
      return is_match;
      } );

    if(found != tail_mbp){
      found->valid = 0;

      // std::cout<< x.hdr_oid 
      //          << ", " << x.hdr_obu_type
      //          << ", " << found->ts -  x.ts  
      //          <<"\n";
      std::cout<<x << " - " << *found << "\n";

    } 
    else {
      std::cout<< "NOT PRESENT: "<< x <<"\n";
    }
  }
}

void md_test_t::consolidate_mbo(){
  auto it = mbo_updates.cbegin();

  do {
    mbo_updates_c.emplace_back(*it);
    // std::cout<< mbo_updates_c.back() <<"  // ";
    it = std::adjacent_find(it, std::cend(mbo_updates), 
      [](const auto & lhs, const auto & rhs){
        return lhs.hdr_oid  != rhs.hdr_oid    ||
        lhs.hdr_obu_type != rhs.hdr_obu_type  ||
        lhs.hdr_symbol != rhs.hdr_symbol      ||
        lhs.hdr_side != rhs.hdr_side          ||
        (static_cast<bool>(lhs.pld_ready) && static_cast<bool>(lhs.pld_valid));
      }
    );
    if (it == mbo_updates.cend()){
      // std::cout << "\n";
      break;
    }
    // std::cout<< *it <<" - ";
    ++it;
    // std::cout<< *it <<" - ";
    
    mbo_updates_c.back().pld_price    = it -> pld_price;
    mbo_updates_c.back().pld_quantity = it -> pld_quantity;

    // std::cout<< mbo_updates_c.back() <<"\n";
  } while(true);
}

void md_test_t::check_unmatched_mbp(){
  for (auto & x  : mbp_updates){
    if (x.valid) { 
      std::cout<<"UNMATCHED: "<< x << "\n";
    }
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
  return mbo_updates_c.size();
}

size_t md_test_t::mbp_size(){
  return mbp_updates.size();
}

