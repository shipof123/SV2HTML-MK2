#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <utility>


template <char delim>
struct SV {
  SV(std::string filename, std::map<std::string, std::string> opts) {
    std::ifstream in(filename);
    
    std::string opt_string = "";
    for(const std::pair<std::string, std::string>& p : opts) {
        opt_string += p.first + "=" + p.second + ' ';
    }
    
    std::cout << "<table " + opt_string + ">\n";
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
    std::map<std::string, std::string> opts = {
        {"border", "1"},
        {"style", "\"color:red\""}
    };
    auto tsv = SV<'-'>("new.tsv", opts);
}
