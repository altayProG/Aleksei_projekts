#pragma once
#include <string>
using namespace std;

class Menu {
private:

    int choice;
    
public:

    Menu();

    class Enterfullname 
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

    class Write 
    {
    private:

        string file_txt = "full_info.txt";

    public:

        void Writef(Enterfullname fullname);

    };
  
    class Read  
    {
    private:

        string file_txt = "full_info.txt";

    public:

        void Readf(Enterfullname fullname);

    };

    class Find
    {
    private:
        string file_txt = "full_info.txt";
    public:
        void Findf(Enterfullname fullname);
    };

};

