#pragma once
#include <string>
using namespace std;

class MENU {
private:
    int choice;
public:
    MENU();
    class INTERFULLNAME 
    {
    private:
        string m_name = "";
        string m_surname = "";
        int m_weight = 0;
        int m_age = 0;
        long long m_phone_number = 0;
        
    public:

        string Enter_name_surname();
        int Enter_age_weight();
        long long Enter_phon_number();
        void Print();

    };

    class WRITE 
    {
    private:
        string file_txt = "full_info.txt";
    public:
        void Write(INTERFULLNAME fullname);
    };

    class READ  
    {
    private:
        string file_txt = "full_info.txt";
    public:
        void Read(INTERFULLNAME fullname);
    };
    
};