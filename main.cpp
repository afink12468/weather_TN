#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using std::cout;
using std::endl;






int main() {


while (getline(cin, line)) {
    extract_values(line, loc, dat);
}

int geocode_to_index(const string &geocode) {
  return (geocode[0]-'A') + 26*(geocode[1]-'A') + 676*(geocode[2]-'A');
}

std::vector<summary> cities(26 * 26 * 26);














    return 0;
}


