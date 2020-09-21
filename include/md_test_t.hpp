#pragma once

#include "mbp_update.hpp"
#include "mbo_update_raw_t.hpp"

using price_t = uint32_t;
using qty_t = uint32_t;
using mbp_side_t = std::map<price_t, qty_t>;
using mbp_side_t_a = std::map<price_t, qty_t, std::less<uint32_t>>;
using mbp_side_t_b = std::map<price_t, qty_t, std::greater<uint32_t>>;

// struct mbp_t
// {
//   mbp_side_t bid;
//   mbp_side_t ask;
//   /* data */
// };

using mbp_t = std::array<mbp_side_t, 2>;
// using mbp_t = std::pair<mbp_side_t_a, mbp_side_t_b>;


class md_test_t
{
  public:
    md_test_t() = default;
    md_test_t(const log_files_t& log_files);
    size_t mbo_size();
    size_t mbp_size();
    std::unordered_map<unique_key_t, std::pair<price_t, qty_t>> mbo;
    std::vector<mbp_t> mbps;

    void sort_entries();
    void match_mbo_mbp(match_fn_t match_fn);
    void consolidate_mbo();
    void check_unmatched_mbp();

  private:
    template <typename update_t,  int m>  std::vector<update_t> read_txt_to_vec(const string& f_name);

    const string _mbo_file_name;
    const string& _mbp_file_name;
    std::vector <mbo_update_raw_t> mbo_updates;
    std::vector <mbo_update_raw_t> mbo_updates_c;
    std::vector <mbp_update_t> mbp_updates;

    void update_mbo(const unique_key_t&, const mbo_update_raw_t &);
    void mbp_add(const price_t p , const qty_t q, const uint32_t sym, const uint32_t side);
    void mbp_exec_del(const price_t p , const qty_t q, const uint32_t sym, const uint32_t side);

};