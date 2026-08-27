struct location {
  string city;
  string state;
  string geocode;

  bool empty();
  bool operator==(const location &loc);
};

struct data {
  int month;
  float precip;
  int temp;
};

class summary {
  public:
    summary();
    summary(const location &loc);

    bool empty();
    const location &get_station();

    void set_station(const location &);
    void add_data(const data &);

    void print_station();
    void print_data();

  private:
    location station;

    int N[12];

    float total_precip[12];
    float max_precip[12];
    float min_precip[12];

    int total_temp[12];
    int max_temp[12];
    int min_temp[12];
};