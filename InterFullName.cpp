#include <iostream>
#include <fstream>
#include <list>
#include <conio.h>
#include <windows.h>
#include "InterFullName.h"

void Write::Readhuman(){
    std::fstream  fs;
    fs.open(m_file_txt, std::fstream::in | std::fstream::out | std::fstream::app);

    if (!fs.is_open())
        std::cout << "Error is open!\n";
    else {

        while (!fs.eof()) {

            getline(fs, m_tempname);
            Printhuman(m_tempname);
            std::cout << std::endl;
        }
    }
    fs.close();
}

void Write::Findhuman() {
    std::string m_file_txt = "full_info.txt";
    fs.open(m_file_txt, std::fstream::in | std::fstream::out | std::fstream::app);

    std::cout << "Enter 2 letters that fine person : ";
    std::cin >> m_find;

    while (fs.get(m_tempname[0]))
    {
        fs.seekg(-1, std::ios::cur);
        getline(fs, m_tempname);

        if (!fs.eof() && m_tempname[0] == m_find[0] && m_tempname[1] == m_find[1])
            Printhuman(m_tempname);
        else
            continue;
    }
    fs.close();
}
void Write::Delhuman() {
    fs.open(m_file_txt, std::fstream::in | std::fstream::out | std::fstream::app);

    std::cout << "Enter 2 letters that fine person : ";
    std::cin >> m_find;
    while (getline(fs, m_tempname) || !fs.eof())
    {
        if (m_tempname[0] != m_find[0] || m_tempname[1] != m_find[1])
        {
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
void Write::Printhuman(std::string m_tempname) {
    std::cout << "\t\t\tName Surname: " << m_tempname << "\n";
}

void Write::Writehuman() {
    fs.open(m_file_txt, std::fstream::in | std::fstream::out | std::fstream::app);

    if (!fs.is_open())
        std::cout << "Error is open!\n";
    else {
        std::cout << "\t\t\t\tIf whant finish tap : # \n";
        for (int n = 1; ; n++) {
    
            std::cout << "\n № " << n << " Enter name : ";
            std::cin >> m_name;

            if ((char)m_name[0] == '#')
                break;
            fs << m_name;
            fs << " ";
            std::cout << "\tSurname : ";
            std::cin >> m_surname;
            fs << m_surname << std::endl;
        }
    }
    fs.close();
}

void Read::Writehuman() {}
void Read::Findhuman() {}
void Read::Delhuman() {}
void Read::Printhuman(std::string m_tempname) {}


void Read::Readhuman() {
    
    fs.open(m_file_txt, std::fstream::in | std::fstream::out | std::fstream::app);

    if (!fs.is_open())
        std::cout << "Error is open!\n";
    else {
        
        while (!fs.eof()){
           
             getline(fs, m_tempname);
             Printhuman(m_tempname);
             std::cout << std::endl;
        }
    }
    fs.close();

}

void Find::Readhuman() {}
void Find::Writehuman() {}
void Find::Delhuman() {}
void Find::Printhuman(std::string m_tempname) {}


void Find::Findhuman(){
    
    fs.open(file_txt, std::fstream::in | std::fstream::out | std::fstream::app);

    std::cout << "Enter 2 letters that fine person : ";
    std::cin >> m_find;

    while (fs.get(m_tempname[0]))
    {
        fs.seekg(-1, std::ios::cur);
        getline(fs, m_tempname);

         if (!fs.eof() && m_tempname[0] == m_find[0] && m_tempname[1] == m_find[1]) 
             Printhuman(m_tempname);
         else
            continue;
    }
    fs.close();
}

void Del::Readhuman() {}
void Del::Writehuman() {}
void Del::Findhuman() {}
void Del::Printhuman(std::string m_tempname) {}


void Del::Delhuman() {

    fs.open(m_file_txt, std::fstream::in | std::fstream::out | std::fstream::app);

    std::cout << "Enter 2 letters that fine person : ";
    std::cin >> m_find;
    while(getline(fs, m_tempname) || !fs.eof())
    {
        if (m_tempname[0] != m_find[0] || m_tempname[1] != m_find[1])
        {
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

Menu::Menu(int choice): m_choice(choice){}

void Menu::Choicehuman(Database& database)
{
    std::cout << "\t\t\t\tenter number menu 1, 2, 3, 4, 5.\n\n "
    << "1 : enter and write\n "
    << "2 : read all info\n "
    << "3 : find one\n "
    << "4 : delete\n "
    << "5 : exit\n ";

    std::cin >> m_choice;
    
    switch (m_choice)
    {
    case 1:
        database.Writehuman();
        Choicehuman(database);
        break;
    case 2:
        database.Readhuman();
        Choicehuman(database);
        break;
    case 3:
        database.Findhuman();
        Choicehuman(database);
        break;
    case 4:
        database.Delhuman();
        Choicehuman(database);
        break;
    case 5:
        break;
    default:

        std::cout << "Error!!! \n Do you thant enter again? yes-1 \n";
        Choicehuman(database);
    }
}

void Print::Readhuman() {}
void Print::Writehuman() {}
void Print::Findhuman() {}
void Print::Delhuman() {}


void Print::Printhuman(std::string m_tempname) {
    std::cout << "\t\t\tName Surname: " << m_tempname << "\n";
}