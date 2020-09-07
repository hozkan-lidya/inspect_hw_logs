#include<cstdint>
#include<tuple>
using timestamp_t = uint64_t;
using oid_t = uint64_t;

struct mbo_update_t
{
  timestamp_t   ts                 ;    
  oid_t         hdr_oid           ;    
  uint32_t      hdr_obu_type      ;   
  uint32_t      hdr_symbol        ;   
  uint32_t      hdr_side          ;   
  uint32_t      hdr_tag           ;   
  uint32_t      hdr_valid         ;   
  uint32_t      pld_quantity      ;   
  uint32_t      pld_price         ;   
  uint32_t      pld_valid         ;   
  uint32_t      tob_update_price  ;   
  uint32_t      tob_update_qty    ;   
  uint32_t      tob_update_symbol ;   
  uint32_t      tob_update_side   ;   
  uint32_t      tob_update_empty  ;   
  uint32_t      top_of_book_valid ;   
  uint32_t      book_stream_price ;   
  uint32_t      book_stream_qty   ;   
  uint32_t      book_stream_symbol;
  uint32_t      book_stream_level ; 
  uint32_t      book_stream_side  ;
  uint32_t      book_stream_valid ;
  uint32_t      book_stream_empty ;
  uint32_t      book_stream_end   ;

  auto members() /*-> decltype(std::tie(a, b, c)) */{
    return std::tie(
                  ts           ,     
                  hdr_oid           ,
                  hdr_obu_type      ,
                  hdr_symbol        ,
                  hdr_side          ,
                  hdr_tag           ,
                  hdr_valid         ,
                  pld_quantity      ,
                  pld_price         ,
                  pld_valid         ,
                  tob_update_price  ,
                  tob_update_qty    ,
                  tob_update_symbol ,
                  tob_update_side   ,
                  tob_update_empty  ,
                  top_of_book_valid ,
                  book_stream_price ,
                  book_stream_qty   ,
                  book_stream_symbol,
                  book_stream_level ,
                  book_stream_side  ,
                  book_stream_valid ,
                  book_stream_empty ,
                  book_stream_end
                  );
  }

  mbo_update_t() = default;


   //  mbo_update_t(mbo_update_t& other);
};