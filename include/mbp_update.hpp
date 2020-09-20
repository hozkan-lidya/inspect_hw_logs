#pragma once
#include "utils.hpp"

struct __attribute__((__packed__)) mbp_update_t
{
  public:
  timestamp_t ts        ;
  uint32_t    oid       ;  // Least significant 32 bits of 64-bit oid variable 
  uint32_t    qty       ;
  uint32_t    price     ;
  uint32_t    valid     ;
  uint32_t    symbol    ;
  uint32_t    side      ;
  uint32_t    add_rm    ;
  uint32_t    tag_valid ;
  uint32_t    tag       ;
  uint32_t    trans_oid ;

  mbp_update_t() = default;
  mbp_update_t(std::array<uint64_t, 11>& arr);
  ~mbp_update_t();
   //  mbo_update_t(mbo_update_t& other);
};
inline std::ostream & operator<<(std::ostream & os, const mbp_update_t& u){
  os<<u.ts<<", "<<u.oid<<", "<<u.price<<", "<<u.qty;
  return os;
}
