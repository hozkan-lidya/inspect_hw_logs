#include<cstdint>
#include<array>
#include<vector>
#include<string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <tuple>

using timestamp_t = uint64_t;
using oid_t = uint64_t;
using std::string;

struct log_files_t
{
  string mbo_file_name;
  string mbp_file_name;

};


struct mbo_update_t
{
  public:
  timestamp_t   ts                ;    
  oid_t         hdr_oid           ;    
  uint32_t      hdr_obu_type      ;   
  uint32_t      hdr_symbol        ;   
  uint32_t      hdr_side          ;   
  uint32_t      hdr_tag           ;   
  uint32_t      hdr_valid         ;   
  uint32_t      pld_quantity      ;   
  uint32_t      pld_price         ;   
  uint32_t      pld_rut           ;   
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

  mbo_update_t() = default;
   
  mbo_update_t(std::array<uint64_t, 25>& arr);
  ~mbo_update_t();
   //  mbo_update_t(mbo_update_t& other);
};

struct mbp_update_t
{
  timestamp_t ts        ;
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
  mbp_update_t(std::array<uint64_t, 10>& arr);
  ~mbp_update_t();
   //  mbo_update_t(mbo_update_t& other);
};

class md_test_t
{
  public:
    md_test_t() = default;
    md_test_t(const log_files_t& log_files);
    size_t mbo_size();
    size_t mbp_size();


  private:
    template <typename update_t, int m>
    std::vector<update_t> read_txt_to_vec(const string f_name);
    
    std::vector <mbo_update_t> _mbo_updates;
    std::vector <mbp_update_t> _mbp_updates;

    const string _mbo_file_name;
    const string& _mbp_file_name;
};