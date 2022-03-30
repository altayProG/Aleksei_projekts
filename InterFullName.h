#pragma once
#include <string>
class Print
{
public:
    Print();
    void Printf(std::string& m_tempname);
};

class Write
{
private:
    std::string m_file_txt = "full_info.txt";
    std::fstream fs;
    std::string m_name;
    std::string m_surname;
public:
    Write();
    Write(std::string name, std::string surname, std::string file_txt);
    void Writef();
};

class Read
{
private:
    std::string m_file_txt = "full_info.txt";
    Print& print;
    std::fstream fs;
    std::string m_tempname;
    std::string m_tempsurname;
public:
    Read(std::string tempname, std::string tempsurname, std::string file_txt, Print& print);
    void Readf();
};

class Find 
{
private:
    std::string file_txt = "full_info.txt";
    Print& print;
    std::fstream fs;
    std::string m_tempname;
    std::string m_find;
    std::string m_ch;
public:
    Find(std::string tempname, std::string find, std::string ch, Print& print);
    void Findf();

};

class Menu 
{
private:
    Write& write;
    Read& read;
    Find& find;
    int m_choice = 0;
public:
    Menu(int choice, Write& write, Read& read, Find& find);
    void Menuf();
    void Choicef();
};



