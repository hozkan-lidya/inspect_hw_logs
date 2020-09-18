#pragma once
#include "utils.hpp"

struct __attribute__((__packed__)) mbo_update_raw_t
{
  public:
  timestamp_t ts                ;    
  oid_t       hdr_oid           ;    
  uint32_t    hdr_obu_type      ;   
  uint32_t    hdr_symbol        ;   
  uint32_t    hdr_side          ;   
  uint32_t    hdr_ready         ;   
  uint32_t    hdr_valid         ;   
  uint32_t    pld_quantity      ;   
  uint32_t    pld_price         ;   
  uint32_t    pld_ready          ;   
  uint32_t    pld_valid          ;   

  mbo_update_raw_t() = default;
  mbo_update_raw_t(std::array<uint64_t, 11>& arr);
  ~mbo_update_raw_t();
   //  mbo_update_t(mbo_update_t& other);
};

inline std::ostream & operator<<(std::ostream & os, const mbo_update_raw_t& u){
  os<<u.ts<<", "<<u.hdr_oid<<"("<<static_cast<uint32_t>(u.hdr_oid)<<"), "<<u.hdr_obu_type<<", "<<u.pld_price<<", "<<u.pld_quantity;
  return os;
}
