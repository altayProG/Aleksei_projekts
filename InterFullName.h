#pragma once
#include <string>
using namespace std;

class MENU {
private:
    int choice;
public:

    MENU();

    class WRITE {

    private:
        string file_txt = "full_info.txt";

    public:
        WRITE(INTERFULLNAME fullname);
    };
};

class INTERFULLNAME {

 private:
     string m_name;
     string m_surname;
     short m_weight;
     short m_age;
     long long m_phone_number;

public:

    INTERFULLNAME();
    void Print();
    class WRITE {

    private:
        string file_txt = "full_info.txt";

    public:
        WRITE(INTERFULLNAME fullname);
    };
};


class WRITE {

private:
    string file_txt = "full_info.txt";

public:
   WRITE(INTERFULLNAME fullname);
};

class READ {

private:
    string file_txt = "full_info.txt";

public:
    READ(INTERFULLNAME fullname);
};