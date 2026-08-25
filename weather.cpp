void extract_values(string &, location &, data &);

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

    cout << dat.month << " "
         << loc.city << " "
         << loc.state << " "
         << loc.geocode << " "
         << dat.precip << " "
         << dat.temp << endl;
}

