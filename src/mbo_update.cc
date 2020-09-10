#include "mbo_update.hpp"

// mbo_update_t::mbo_update_t(){

// }
// struct mbo_update_t;

mbo_update_t::mbo_update_t(std::array<uint64_t, 25>& arr) : 
ts                (arr[0]), 
hdr_oid           (arr[1]), 
hdr_obu_type      (arr[2]), 
hdr_symbol        (arr[3]), 
hdr_side          (arr[4]), 
hdr_tag           (arr[5]), 
hdr_valid         (arr[6]), 
pld_quantity      (arr[7]), 
pld_price         (arr[8]), 
pld_rut           (arr[9]),
pld_valid         (arr[10]) ,
tob_update_price  (arr[11]),  
tob_update_qty    (arr[12]),  
tob_update_symbol (arr[13]),  
tob_update_side   (arr[14]),  
tob_update_empty  (arr[15]),  
top_of_book_valid (arr[16]),  
book_stream_price (arr[17]),  
book_stream_qty   (arr[18]),  
book_stream_symbol(arr[19]),  
book_stream_level (arr[20]),  
book_stream_side  (arr[21]),  
book_stream_valid (arr[22]),  
book_stream_empty (arr[23]),  
book_stream_end   (arr[24])


{
 // NOP
}
mbo_update_t::~mbo_update_t() {}


mbp_update_t::mbp_update_t(std::array<uint64_t, 10>& arr) : 
ts          (arr[0]), 
qty         (arr[1]), 
price       (arr[2]), 
valid       (arr[3]), 
symbol      (arr[4]), 
side        (arr[5]), 
add_rm      (arr[6]), 
tag_valid   (arr[7]), 
tag         (arr[8]), 
trans_oid   (arr[9])
{
  // NOP
}
mbp_update_t::~mbp_update_t() {}


md_test_t::md_test_t(const log_files_t& log_files) :
_mbo_file_name(log_files.mbo_file_name),
_mbp_file_name(log_files.mbp_file_name) {
  // NOP
}

