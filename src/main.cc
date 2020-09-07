#include <iostream>
#include <fstream>
#include <ostream>

using std::string;
using std::cout;
using std::ifstream;
using std::getline;

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
  
  string line;
  while (getline(in_file, line, ' '))
  {
    cout << line << ", ";
  }
  cout << "\n";
  
}

int main()
{
  read_1("./mbpu_200904_0.log");    

}