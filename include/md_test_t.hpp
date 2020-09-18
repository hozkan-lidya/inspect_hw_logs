#pragma once

#include "mbp_update.hpp"
#include "mbo_update_raw_t.hpp"

class md_test_t
{
  public:
    md_test_t() = default;
    md_test_t(const log_files_t& log_files);
    size_t mbo_size();
    size_t mbp_size();

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
};