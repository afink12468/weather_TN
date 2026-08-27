#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "weather.h"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::fixed;
using std::setprecision;

bool location::empty() const { // location function that returns true if the certain geocode is empty and false if it contains a geocode.
  if(geocode.empty()) {
    return true;
  }
  else {
     return false;
  }
}




bool location::operator==(const location &loc) const {
  if(geocode == loc.geocode) { // location function that determines if two geocodes are the samee based on their station.
    return true;
  }
  else {
     return false;
  }
}



summary::summary() {
  station.city = ""; // Updated constructor for the summary class. Station information is kept to a blank string.
  station.state = "";
  station.geocode = "";

  for(int i = 0; i < 12; i++) { // This for loop, like the original contructor, initializes each base value to be altered by the first data entry in the file. However, each now has 12 elements of 0 to account for 
    N[i] = 0;                   // 12 month of data. 

    total_temp[i] = 0;
    total_precip[i] = 0;
    max_precip[i] = 0;
    max_temp[i] = -1000;
    min_precip[i] = 10000;
    min_temp[i] = 10000;
  }
}





summary::summary(const location &loc) { // Another summary constructor. The point of this is to create another summary object in relation to a station.
  station = loc;

  for(int i = 0; i < 12; i++) {
    N[i] = 0;

    total_temp[i] = 0;
    total_precip[i] = 0;
    max_precip[i] = 0;
    max_temp[i] = -1000;
    min_precip[i] = 10000;
    min_temp[i] = 10000;
  }

}

bool summary::empty() {
  if(station.geocode.empty()) {  // functin for checking if a geocode is empty or not and returns true or false based on the results.
    return true;
  }
  else {
    return false;
  }
 }

const location &summary::get_station() const { // get station function that returns said station
  return station;
}

  

  void summary::set_station(const location &loc) { // sets each element of the location struct (now a station variable) into a location object. (loc) .
  station.city = loc.city;
  station.state = loc.state;
  station.geocode = loc.geocode;
}

void summary::add_data(const data &d) { // add data function that increments 'N' as a counter for the amount of months being processed. This calculates average, max, and min values for precip and temp.
  int month = d.month - 1;

  N[month]++;

   total_precip[month] = total_precip[month] + d.precip;
  total_temp[month] = total_temp[month] + d.temp;

  if(d.temp > max_temp[month]) {
    max_temp[month] = d.temp;
  }

  if(d.precip > max_precip[month]) {
    max_precip[month] = d.precip;
  }

  if(d.temp < min_temp[month]) {
    min_temp[month] = d.temp;
  }

  if(d.precip < min_precip[month]) {
    min_precip[month] = d.precip;
  }
}





void summary::print_station() {
  cout << "------------------------------------------" << endl; // print station function. It prints this line in the final result, for example:  Knoxville, Tennessee (TYS). Along with the dashed lines, of course.

  cout << station.city
       << ","
       << ' '
       << station.state
       << ' '
       << "(" << station.geocode << ")" << endl;
  cout << "------------------------------------------" << endl;
}

void summary::print_data() { // print data function. This prints the actual data calculated in the add_data function. An array of each month of the year is added to precede each line. Static_cast is used when needed to make sure a number is the correct data type.
  string months[12] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
  };

  
  
  for(int i = 0; i < 12; i++) {
    if(N[i] > 0) {
      float overall_precip = total_precip[i] / N[i];
      float overall_temp = static_cast<float>(total_temp[i]) / N[i];

      cout << months[i] << ":  "
           << fixed << setprecision(2)
           << total_precip[i] << "  "
           << overall_precip << "  "
           << max_precip[i] << "  "
           << min_precip[i]
           << " :  "
           << static_cast<int>(overall_temp) << "  "
           << max_temp[i] << "  "
           << min_temp[i] << endl;
    }
  }
}