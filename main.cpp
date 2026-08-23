#include <iostream> 
#include <string>
#include <fstream>
using std::cout;
using std::endl;

struct location {
  string city;
  string state;
  string geocode;
};

struct data {
  int month;
  float precip;
  int temp;
};

void extract_values(string &, location &, data &);


int main() {

















    return 0;
}


void extract_values(string &line, location &loc, data &dat) {
std::string line;
while(std::getline(cin,line)) {
  for(int i = 0; i < line.length(); i++) {
    if(line[i] == ' ') {
      line[i] = '_' ;
    }
  }

  for(int i = 0; i < line.length(); i++) {
    if(line[i] == ',') {
      line[i] = ' ' ;
    }
  }

  std::stringstream ss(line); 
  ss >> dat.month;
  ss >> loc.city;
  ss >> loc.state;
  ss >> loc.geocode;
  ss >> dat.precip;
  ss >> dat.temp;


}

}