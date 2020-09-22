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
#include <cassert>
#include <memory> 
#include <map>
#include <stdexcept>
#include <variant>
#include <any>




// #include <stdint.h>
using std::string;

using timestamp_t = uint64_t;
using oid_t       = uint64_t;
using symbol_t    = uint16_t;
using match_fn_t  = std::function<void(uint64_t)>;

template <typename T>
void foo()
{
    std::cout << "foo!" << (T)3.14f << std::endl;
}
struct log_files_t
{
  string mbo_file_name;
  string mbp_file_name;

};

struct unique_key_t
{
  oid_t    oid;
  symbol_t sym;
  bool    side;

  bool operator==(const unique_key_t &other) const
  { return (oid == other.oid
            && sym == other.sym
            && side == other.side);
  }
};

namespace std {

  template <>
  struct hash<unique_key_t>
  {
    std::size_t operator()(const unique_key_t& k) const
    {
      using std::hash;
      // Compute individual hash values for first,
      // second and third and combine them using XOR
      // and bit shifting:
      uint64_t res =  (k.oid << 17)                     |
                      static_cast<uint64_t>(k.sym << 1) |
                      static_cast<uint64_t>(k.side);
      return hash<uint64_t>()(res);
    }
  };

}
