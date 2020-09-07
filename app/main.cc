#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <vector>
#include <tuple>
#include "mbo_update.hpp"

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::getline;
using std::stringstream;

using bb_tuple_t = std::tuple < uint64_t,uint64_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t
                               ,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t
                               ,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t
                               >;



void read_1(std::string file_name){
  std::ifstream in_file;
  in_file.open(file_name);
  if (in_file.is_open()) {
    cout<<"ahaha\n";
    // int number;
    string str;
    // char c;
    string line;
    while(in_file >> str ){
        std::cout << str << "\n";
        }
  }
  in_file.close();
}

void read_2(std::string file_name) {
  mbo_update_t mbo_update;
  mbo_update.members() = std::make_tuple(1, 2, 3, 1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3,1, 2, 3);
  cout<<mbo_update.hdr_oid;
  
  // mbo_update =  (mbo_update_t){ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  // (void)mbo_update;
 
  std::vector <mbo_update_t> mbo_updates;
  // mbo_updates.emplace_back(mbo_update_t{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1});
  mbo_updates.emplace_back(std::move(mbo_update));
  std::ifstream in_file(file_name);
  int k =0;
  std::string line, ss;
  int n ;
  bb_tuple_t bb_tuple{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  while (getline(in_file, line))
  {

    auto x = line.c_str()[0];
    if (x != '='){
      k++;
      std::stringstream ss_line(line);
      ss_line >> ss;
      // cout << ss<< "\n ";

      ss_line >> n;
      auto nn = k % 24;
      std::get< 0>(bb_tuple) = 6;
      cout << std::get<0>(bb_tuple) << "\n ";
    }
    else{
      
    }
  }
  //  cout << "k: " << k  << "\n"; 
}
int main()
{
  read_2("data/bb_200904_0.log");    
}
