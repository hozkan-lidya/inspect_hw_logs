#include "md_test_t.hpp"

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::getline;
using std::stringstream;


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

template <int m, typename update_t>
void read_2(std::string file_name) {

  std::vector <update_t> updates;
  updates.reserve(0xFFFF);
  int k =0;


  std::ifstream in_file(file_name);
  std::string line, ss;

  std::array<uint64_t, m> temp_arr;
  
  while (getline(in_file, line))
  {
    auto x = line.c_str()[0];
    if (x == '='){
      cout<<x<<"\n";
      continue;
    }
    std::stringstream ss_line(line);
    ss_line >> ss;
    // cout << ss<< "\n ";

    ss_line >> temp_arr[ k++ ];
    if (k ==m){
      k = 0;
      updates.emplace_back(temp_arr);
      auto mm = updates.back();
      cout<< updates.back().ts<<", ";
      cout<<"\n";
    }

    }

}

int main()
{
  // read_2<25, mbo_update_t>("data/bb_200904_0.log");
  log_files_t log_files;
  log_files.mbo_file_name = "data/bb_200902_0.log";
  log_files.mbp_file_name = "data/mbpu_200902_0.log";
  md_test_t md_test(log_files);
  cout<< md_test.mbo_size() << " - " << md_test.mbp_size() <<"\n";
  cout<< md_test.mbo_updates[0].hdr_oid << " - " << md_test.mbo_updates[0].ts <<"\n";

}
