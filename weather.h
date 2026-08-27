#ifndef SUPPORT_H
#define SUPPORT_H

#include <string>

using std::string; // This file mostly just holds data to be used in functions in other files. (location and data struct + summary file) .

struct location { // location struct
  string city;
  string state;
  string geocode;

  bool empty() const;
  bool operator==(const location &loc) const;
};

struct data { // data struct
  int month;
  float precip;
  int temp;
};

class summary {
  public:
    summary();
    summary(const location &loc); // member functions

    bool empty();
    const location &get_station() const;

    void set_station(const location &);
    void add_data(const data &);

    void print_station();
    void print_data();

  private:
    location station;

    int N[12]; // All stats were updated in phase 3 to hold the data for 12 months.

    float total_precip[12]; 
    float max_precip[12];
    float min_precip[12];

    int total_temp[12];
    int max_temp[12];
    int min_temp[12];
};

#endif