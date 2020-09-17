#include "mbp_update.hpp"

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

