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

class summary {
  public:
    summary() {
      station = " ";
      N = 0;
      total_temp = 0;
      total_precip = 0;
      max_precip = 0;
      max_temp = -1000;
      min_precip = 10000;
      min_temp = 10000;
    }

    bool empty()
    
    void set_station(const location &);
    void add_data(const data &);

    void print_station();
    void print_data();

  private:
    location station;

    int N;

    float total_precip;
    float max_precip;
    float min_precip;

    int total_temp;
    int max_temp;
    int min_temp;
};

bool empty() {
  if(station.geocode.empty()) {
    return false;
        }

  else{
    return true;
  }
}


void set_station(const location &) {
  location.city = station.city;
  location.state = station.state;
  location.geocode = station.geocode;
}


void add_data(const data & d) {
  N++ ;
  total_precip = data.precip + total_precip;
  total_temp = data.temp + total_temp;

  if(d.temp > max_temp) {
    d.temp = max_temp;
  }

  if(d.precip > max_precip) {
    d.precip = max_precip;
  }

if(d.temp < min_temp) {
    d.temp = min_temp;
  }


  if(d.precip < min_precip) {
    d.precip = min_precip;
  }

}

void print_station() {
cout << station.city  
<< ',' 
<< ' ' 
<< station.state 
<< ' ' 
<< "(" << station.geocode << ")" << endl;
}


void print_data() {
  float overall_precip = total_precip / N;
  float overall_temp = static_cast<float>(total_temp) / N;

  cout << ">>> "
  << total_precip << " "
  << overall_precip << " "
  << max_precip << " "
  << min_precip
  << " : "
  << overall_temp << " "
  << max_temp << " "
  << min_temp << endl;
}