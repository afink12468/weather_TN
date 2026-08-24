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
    summary();

    bool empty();
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