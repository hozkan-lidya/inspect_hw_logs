#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>

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

void read_2(std::string file_name) {
  std::ifstream in_file(file_name);
  
  std::string line, ss;
  uint64_t n;
  
  while (getline(in_file, line))
  {
    auto x = line.c_str()[0];
    if (x != '='){
      std::stringstream ss_line(line);
      
      ss_line >> ss;
      // cout << ss<< "\n ";
      
      ss_line >> n;
      cout << n << "\n ";
    }
    else{
      // cout<< x <<endl;
    }
  }
  // cout << "\n";
  
}

int main()
{
  read_2("data/bb_200902_0.log");    
}
