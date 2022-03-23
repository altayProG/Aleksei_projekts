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
};

class Write 
{
private:
    std::string file_txt = "full_info.txt";
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
    void Printf(std::string &m_tempname);
    
};

class Find:protected Read
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
