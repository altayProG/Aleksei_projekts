#pragma once
#include <string>
using namespace std;

class InterFullName {

 private:
     string m_name;
     string m_surname;
     short m_weight;
     short m_age;
     long long m_phone_number;

public:

    InterFullName();
    void Print();
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