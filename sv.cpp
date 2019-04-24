#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
template <char delim>
struct SV {
  SV(std::string filename) {
    std::ifstream in(filename);
    std::cout << "<table>\n";
    std::string line, value;
    while(getline(in, line)) {
      auto linestream = std::istringstream(line);
      std::cout << "<tr>\t";
      while(getline(linestream, value, delim)) {
        std::cout << "<td>" << value << "</td>\t";
      }
      std::cout << "</tr>\n";
    }
    std::cout << "</table>" << std::endl;
  }
};

int main(){
    auto tsv = SV<' '>("new.tsv");
}
