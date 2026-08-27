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

bool location::empty() {
  if(geocode.empty()) {
    return true;
  }
  else {
    return false;
  }
}

bool location::operator==(const location &loc) {
  if(geocode == loc.geocode) {
    return true;
  }
  else {
    return false;
  }
}

summary::summary() {
  station.city = "";
  station.state = "";
  station.geocode = "";

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

summary::summary(const location &loc) {
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
  if(station.geocode.empty()) {
    return true;
  }
  else {
    return false;
  }
}

const location &summary::get_station() {
  return station;
}

void summary::set_station(const location &loc) {
  station.city = loc.city;
  station.state = loc.state;
  station.geocode = loc.geocode;
}

void summary::add_data(const data &d) {
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
  cout << "------------------------------------------" << endl;
  cout << station.city
       << ","
       << ' '
       << station.state
       << ' '
       << "(" << station.geocode << ")" << endl;
  cout << "------------------------------------------" << endl;
}

void summary::print_data() {
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
           << total_precip[i] << " "
           << overall_precip << " "
           << max_precip[i] << " "
           << min_precip[i]
           << " :  "
           << static_cast<int>(overall_temp) << " "
           << max_temp[i] << " "
           << min_temp[i] << endl;
    }
  }
}