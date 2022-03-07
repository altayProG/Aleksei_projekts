#pragma once
#include <string>
using namespace std;

class MENU {
private:
    int choice;
public:
    class INTERFULLNAME //: public MENU 
    {
    private:
        
    public:
    
        string m_name;
        string m_surname;
        int m_weight;
        int m_age;
        long long m_phone_number;

        string INTERFULLNAMEff();
        int INTERFULLNAMEf();
        long long INTERFULLNAMEfff();
        void Print();

    };

    class WRITE //: public MENU 
    {
    public:

        string file_txt = "full_info.txt";
        void WRITEf(INTERFULLNAME fullname);


    };

    class READ //: public MENU 
    {
    public:

        string file_txt = "full_info.txt";
        void READf(INTERFULLNAME fullname);
    };
    
    MENU();
};



//class INTERFULLNAME //: public MENU 
//{
//
//private:
//    string m_name;
//    string m_surname;
//    short m_weight;
//    short m_age;
//    long long m_phone_number;
//
//public:
//
//    INTERFULLNAME();
//    void Print();
//    
//};


//class WRITE //: public MENU 
//{
//
//private:
//    string file_txt = "full_info.txt";
//    
//public:
//    WRITE(INTERFULLNAME fullname);
//};

//class READ //: public MENU 
//{
//
//private:
//    string file_txt = "full_info.txt";
//    
//public:
//    READ(INTERFULLNAME fullname);
//};