#pragma once
#include <string>
using namespace std;

class InterFullName {

 private:
    string name;
    long long pone_number;

public:

    InterFullName();
    void Print();
};

class WriteRead {

public:
    WriteRead();
};

class Write {

private:
    string file_txt = "full_info.txt";

public:
    Write(InterFullName fullname);
};

class Read {

private:
    string file_txt = "full_info.txt";

public:
    Read(InterFullName fullname);
};

class WR {

public:
    WR();
};