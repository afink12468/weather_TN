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

location loc_;
data dat_ ;

std::vector<summary> cities(26 * 26 * 26);

geocode_to_index(loc_.geocode) ;

if(empty() != false) {
    set_station(loc_) ;
}

add_data(dat) ;



for(int i = 0; i < 17576; i++) {
    if(cities[i].empty()) {
    continue;
    }
    else {
        print_station() ;
        print_data() ;
    }
}








    return 0;
}


