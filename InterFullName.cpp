#include <iostream>
#include <fstream>
#include <list>
#include "InterFullName.h"

Print::Print() {}

void Print::Printf(std::string& m_tempname) {
    std::cout << "\t\t\tName Surname: " << m_tempname << "\n";
}

Write::Write() {}

Write::Write(std::string name, std::string surname, std::string file_txt)
    : m_name(name), m_surname(surname), m_file_txt(file_txt) {}

void Write::Writef() {
    std::fstream fs;

    fs.open(m_file_txt, std::fstream::in | std::fstream::out | std::fstream::app);

    std::cout << "\t\t\tIf you whana finihsd enter name, tap : # \n";

    for (int n = 1; ; n++) {

        std::cout << "\n № " << n << " Enter name : ";
        std::cin >> m_name;

        if (m_name[0] == '#')
            break;

        fs << m_name;
        fs << " ";
        std::cout << "  Enter surname : ";
        std::cin >> m_surname;
        fs << m_surname << std::endl;
    }
    fs.close();
}

Read::Read(std::string tempname, std::string file_txt, Print& print)
    : m_tempname(tempname), m_file_txt(file_txt), print(print) {}

void Read::Readf() {
    fs.open(m_file_txt, std::fstream::in | std::fstream::out | std::fstream::app);

    while (!fs.eof()) {
        m_tempname = " ";
        getline(fs, m_tempname);
        print.Printf(m_tempname);
        std::cout << std::endl;
    }
    fs.close();
}

Find::Find(std::string tempname, std::string find, Print& print)
    : m_tempname(tempname), m_find(find), print(print) {}

void Find::Findf() {

    fs.open(file_txt, std::fstream::in | std::fstream::out | std::fstream::app);

    std::cout << "Enter 2 letters that fine person : ";
    std::cin >> m_find;

    while (fs.get(m_tempname[0])){
        fs.seekg(-1, std::ios::cur);
        getline(fs, m_tempname);

        if (m_tempname[0] == m_find[0] && m_tempname[1] == m_find[1])
            print.Printf(m_tempname);
    }
    fs.close();
}

Del::Del(std::string tempname, std::string find, Print& print)
    : m_tempname(tempname), m_find(find), print(print) {};

void Del::Delf() {

    fs.open(m_file_txt, std::fstream::in | std::fstream::out | std::fstream::app);
    std::cout << "Enter 2 letters that fine person : ";
    std::cin >> m_find;

    while (getline(fs, m_tempname) || !fs.eof()){

        if (m_tempname[0] != m_find[0] || m_tempname[1] != m_find[1]){
            fdel.open(m_del_file_txt, std::fstream::in | std::fstream::out | std::fstream::app);
            fdel << m_tempname << std::endl;
        }
        fdel.close();
    }
    fs.close();
    fs.open(m_file_txt, std::fstream::out);
    fs.close();

    fdel.open(m_del_file_txt, std::fstream::in | std::fstream::out | std::fstream::app);
    fs.open(m_file_txt, std::fstream::in | std::fstream::out | std::fstream::app);

    while (getline(fdel, m_tempname) || !fdel.eof()) 
        fs << m_tempname << std::endl;
     
    fdel.close();
    fdel.open(m_del_file_txt, std::fstream::out);
    fdel.close();
    fs.close();
}

Menu::Menu(int choice, Write& write, Read& read, Find& find, Del& del)
    : m_choice(choice), write(write), read(read), find(find), del(del) {}

void Menu::Menuf()
{
    std::cout << "enter number menu 1, 2, 3, 4, 5.\n "
    << "1 : enter and write\n "
    << "2 : read all info\n "
    << "3 : find one\n "
    << "4 : delete\n "
    << "5 : exit\n ";
    std::cin >> m_choice;

    switch (m_choice)
    {
    case 1:
        write.Writef();
        Menuf();
        break;
    case 2:
        read.Readf();
        Menuf();
        break;
    case 3:
        find.Findf();
        Menuf();
        break;
    case 4:
        del.Delf();
        Menuf();
        break;
    case 5:
        break;
    default:
        std::cout << "Error!!!\n";
        Menuf();
    }
}