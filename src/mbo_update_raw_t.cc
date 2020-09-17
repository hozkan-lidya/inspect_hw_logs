#include "mbo_update_raw_t.hpp"


mbo_update_raw_t::mbo_update_raw_t(std::array<uint64_t, 11>& arr) :
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

{
 // NOP
}
mbo_update_raw_t::~mbo_update_raw_t() {}
