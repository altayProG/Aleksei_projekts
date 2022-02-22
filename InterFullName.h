#pragma once
#include <string>
using namespace std;



class Menu {
public:
    enum Menu_enum {
        SAVE_FULL_INFO,
        GET_FULL_INFO,
    };
    int Getm(m);
    switch ();
private:
    Menu_enum m;
};

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
