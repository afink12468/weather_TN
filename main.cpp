#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
#include "weather.h"

using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::cin;
using std::vector;
using std::stringstream;


void extract_values(string &line, location &loc, data &dat) {

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ') {
            line[i] = '_';
        }
    }

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ',') {
            line[i] = ' ';
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


int isgeocode(const string &geocode) {

  if(geocode.length() != 3) {
    return false;
  }

  for(int i = 0; i < 3; i++) {
    if(!isupper(geocode[i])) {
      return false;
    }
  }

  return true;
}


int main(int argc, char *argv[]) {

  if(argc > 2) {
    cout << "usage: ./Prog1 [geocode] < datafile" << endl;
    return 1;
  }

  string requested_geocode = "";

  if(argc == 2) {
    requested_geocode = argv[1];

    if(!isgeocode(requested_geocode)) {
      cout << "usage: ./Prog1 [geocode] < datafile" << endl;
      return 1;
    }
  }

  string line;
  location loc;
  data dat;

  vector<summary> cities;

  while(getline(cin, line)) {

    extract_values(line, loc, dat);

    int index = -1;

    for(int i = 0; i < cities.size(); i++) {
      if(cities[i].get_station() == loc) {
        index = i;
        break;
      }
    }

    if(index == -1) {
      cities.push_back(summary(loc));
      index = cities.size() - 1;
    }

    cities[index].add_data(dat);
  }


  for(int i = 0; i < cities.size(); i++) {

    if(requested_geocode.empty()) {
      cities[i].print_station();
      cities[i].print_data();
    }
    else if(cities[i].get_station().geocode == requested_geocode) {
      cities[i].print_station();
      cities[i].print_data();
    }
  }


  return 0;
}