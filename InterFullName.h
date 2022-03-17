#pragma once
#include <string>
using namespace std;

class Menu 
{
private:

    int m_choice = 0;
    
public:
    
    Menu();
    Menu(int choice);
    void setMenu(int choice);
    int getMenu();
    void Menuf();
};

class Print
{

};

class Enterfullname
{
private:

    string m_name = " ";
    string m_surname = " ";
    int m_weight = 0;
    int m_age = 0;
    long long m_phone_number = 0;

public:

    Enterfullname();

    Enterfullname(string name, string surname, int weight, int age, long long phone_number);
     
    void setName_surname(string name, string surname);
    string getName_surname();

    void setAge_weight(int weight, int age);
    int getAge_weight();

    void setPhon_number(long long phone_number);
    long long getPhon_number();

    string Enter_name_surname();
    int Enter_age_weight();
    long long Enter_phon_number();
    void Print();
};

class Write : public Enterfullname
{
private:

    string file_txt = "full_info.txt";

public:

    void Writef(Enterfullname &fullname);

};

class Read
{
private:

    string file_txt = "full_info.txt";
    fstream fs;
public:

    void Readf(Enterfullname &fullname);

};

//class Find
//{
//private:
//    string file_txt = "full_info.txt";
//    fstream fs;
//    char find_letter;
//    char ch;
//public:
//    void Findf(Enterfullname fullname);
//};
