#include <stringstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct SV<char delim> {
  SV(std::string filename) {
    std::ifstream in(filename);
    
    std::string line, value;
    while(getline(in, line)) {
      auto linestream = std::istringstream(line);
      std::cout << "<hr>\n|";
      while(getline(linestream, value, delim)) {
        std::cout << value << " | "
      }
      std::cout << "<hr>" << std::endl;
    }
  }
}
