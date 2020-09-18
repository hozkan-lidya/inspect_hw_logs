#include "md_test_t.hpp"

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::getline;
using std::stringstream;

int main(int argc, char *argv[])
{
  auto cmd_0 = string("cut -d' ' -f2- ") + argv[1] + string(" | grep '^[0-9]' > /tmp/bb.txt") ;
  auto cmd_1 = string("cut -d' ' -f2- ") + argv[2] + string(" | grep '^[0-9]' > /tmp/mbpu.txt") ;
  // auto cmd_1 = string("head ") + string(argv[1]) ;

  std::system(cmd_0.c_str()); // execute the UNIX command "ls -l >test.txt"
  std::system(cmd_1.c_str()); // execute the UNIX command "ls -l >test.txt"
  // std::cout << std::ifstream("test.txt").rdbuf();
  (void)argc;
  log_files_t log_files{
  // "../data/bb_200914_0.log", 
  // "../data/mbpu_200914_0_Corrected.log"
  // argv[1] , argv[2]
  "/tmp/bb.txt", 
  "/tmp/mbpu.txt"
  };
  
  md_test_t md_test(log_files);
  // md_test.sort_entries();
  // cout<< md_test.mbo_size() << " - " << md_test.mbp_size() <<"\n";
  md_test.consolidate_mbo();
  
  auto foo_f = [] (int m) -> void {
    ++m;
    // NOP
  };

  md_test.match_mbo_mbp( foo_f );
  md_test.check_unmatched_mbp();
  // std::cout<<"mbo_size: "<<md_test.mbo_size()<<"\n";
}