#pragma once
#include <string>

class Write
{
private:
    std::string file_txt = "full_info.txt";
    std::fstream fs;
    std::string m_name;
    std::string m_surname;
public:
    Write();
    Write(std::string name, std::string surname);
    void Writef();
};

class Read
{
private:
    std::string file_txt = "full_info.txt";
    std::fstream fs;
    std::string m_tempname;
    std::string m_tempsurname;
public:
    Read();
    Read(std::string tempname, std::string tempsurname);
    void Readf();
    void Printf(std::string& m_tempname);

};

class Find :protected Read
{
private:
    std::string file_txt = "full_info.txt";
    std::fstream fs;
    std::string m_tempname;
    std::string m_find;
    std::string m_ch;
public:
    Find();
    Find(std::string tempname, std::string find, std::string ch);
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
    Menu() = delete;
    Menu(int choice, Write& write, Read& read, Find& find);
    void Menuf();
    void Choicef();
};


