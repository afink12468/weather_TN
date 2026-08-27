#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
#include "Support.h"

using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::cin;
using std::vector;
using std::stringstream;


void extract_values(string &line, location &loc, data &dat) { // function for extracting the contents of the file
                                                              // It first checks each line for a space to replace with an underscore. Then does the same with commas -> spaces.
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
                                                            // After swapping the necessary characters, a stringstream is applied to break each element off into separate pieces.
    std::stringstream ss(line);

    ss >> dat.month;
    ss >> loc.city;
    ss >> loc.state;
    ss >> loc.geocode;
    ss >> dat.precip;
    ss >> dat.temp;
}


int isgeocode(const string &geocode) {   // function for checking geocode status. A geocode must be 3 characters and all uppercase (hence it returns false if the length isn't 3 and also if all characters aren't uppercase.)

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

  if(argc > 2) {  // optional command line argument
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
  location loc; // 
  data dat;

  vector<summary> cities; 

  while(getline(cin, line)) {   

    extract_values(line, loc, dat); // values of the file are extracted contiously while the file is getting read. This is because it reads them one line at a time.

    int index = -1;

    for(int i = 0; i < cities.size(); i++) {
      if(cities[i].get_station() == loc) {    // This for loop reads through the vector of cities and checks if the data for that city has already been recorded.  
        index = i;
        break;
      }
    }

    if(index == -1) {
      cities.push_back(summary(loc));
      index = cities.size() - 1;
    }
                                              // If the search for the city fails, it pushes back a location object to create a new "city" and then adds the data to the add data function.
    cities[index].add_data(dat);
  }


  for(int i = 0; i < cities.size(); i++) { // This for loop prints every city as the first condition. If the user requests a specific geocode in the command line, it prints that.

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