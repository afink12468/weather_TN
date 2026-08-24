void extract_values(string &, location &, data &);

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

 cout << line << endl;
}

}

void add_data(const data & , int N);

void add_data(const data & , int N) { // month precip and temp (data)
N = 0;
while(std::getline(cin,line)) {
    N++;
    
}