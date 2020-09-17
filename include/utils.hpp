#pragma once

#include <string.h>
#include<cstdint>
#include<array>
#include<vector>
#include<string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <functional>
#include <algorithm>

// #include <stdint.h>

using timestamp_t = uint64_t;
using oid_t = uint64_t;
using std::string;
using match_fn_t = std::function<void(int)>;


struct log_files_t
{
  string mbo_file_name;
  string mbp_file_name;

};

