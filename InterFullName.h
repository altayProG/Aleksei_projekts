#pragma once
#include <string>


class Menu 
{
private:

    int m_choice = 0;
    
public:
    
    Menu();
    Menu(int choice);
    void Menuf();
    void Choicef();
    void exit();
};

class Enterfullname 
{
private:

    std::string m_name = " ";
    std::string m_surname = " ";
    int m_weight = 0;
    int m_age = 0;
    long long m_phone_number = 0;
    
public:
    
    Enterfullname();
    Enterfullname(std::string name, std::string surname, int weight, int age, long long phone_number);
    std::string Enter_name_surname();
    int Enter_age_weight();
    long long Enter_phon_number();
    void Printf();
};

class Write 
{
private:

    std::string file_txt = "full_info.txt";

public:

    void Writef(Enterfullname &fullname);

};

class Read
{
private:

    std::string file_txt = "full_info.txt";
    std::fstream fs;
public:

    void Readf(Enterfullname &fullname);

};

//class Find
//{
//private:
//    string file_txt = "full_info.txt";
//    fstream fs;
//    string m_find_letter = " ";
//    char m_ch = ' ';
//public:
//    Find();
//    Find(string find_letter, char ch);
//    void Findf(Enterfullname &fullname);
//};
