#include <iostream>
#include <fstream>
#include "InterFullName.h"

Write::Write() {}

Write::Write(std::string name, std::string surname)
        : m_name(name), m_surname(surname){}

void Write::Writef() {
    std::fstream fs;

    fs.open(file_txt, std::fstream::in | std::fstream::out | std::fstream::app);

    if (!fs.is_open())
        std::cout << "Error is open!\n";
    else {
        std::cout << "File is open!\n";
        std::cout << "Enter name and surname :\n";
        std::cin >> m_name >> m_surname;
        fs << m_name;
        fs << " ";
        fs << m_surname << std::endl;
        
    }
    fs.close();

}

Read::Read(){}

Read::Read(std::string tempname, std::string tempsurname)
        : m_tempname(tempname), m_tempsurname(tempsurname){}

void Read::Readf() {
    
    fs.open(file_txt, std::fstream::in | std::fstream::out | std::fstream::app);

    if (!fs.is_open())
        std::cout << "Error is open!\n";
    else {
        std::cout << "File is open!\n";
        
        while (!fs.eof()) {
            m_tempname = "";
            getline(fs, m_tempname);
            Printf(m_tempname);
            
            std::cout << "\n";
        }
    }
    fs.close();

}

void Read::Printf(std::string &m_tempname){
    std::cout << "\t\t\tName Surname: " << m_tempname << "\n";
}

Find::Find(){}

Find::Find(std::string tempname, std::string find, std::string ch)
    : m_tempname(tempname), m_find(find), m_ch(ch){}

void Find::Findf(){
    
    fs.open(file_txt, std::fstream::in | std::fstream::out | std::fstream::app);

    if (!fs.is_open())
        std::cout << "Error is open!!\n";
    else {
        std::cout << "File is open!\n";
        std::cout << "Enter 2 letters that fine person : ";
        std::cin >> m_find;

        while (fs.get(m_ch[0]))
        {
            if (m_ch[0] == m_find[0])
            {
                if (!fs.eof()) {
                    fs.seekg(-1, std::ios::cur);
                    getline(fs, m_tempname);
                    if ((char)m_tempname[0] == (char)m_find[0] && (char)m_tempname[1] == (char)m_find[1])
                    {
                         Printf(m_tempname);
                           //break;
                    }
                }
            }
        }
    }
    fs.close();
}

Menu::Menu(int choice, Write& write, Read& read, Find& find)
    : m_choice(choice), write(write), read(read), find(find) {}

void Menu::Choicef()
{
    std::cout << "Will you whant enter one more time? : 1 , No : 2\n";
    std::cin >> m_choice;
    if (m_choice == 1)
        Menuf();
}

void Menu::Menuf()
{
    std::cout << "enter number menu 1, 2, 3.\n "
        << "1 : enter and write\n "
        << "2 : read all info\n "
        << "3 : find one\n";
    std::cin >> m_choice;

    switch (m_choice)
    {
    case 1:
        write.Writef();
        Choicef();
        break;
    case 2:
        read.Readf();
        Choicef();
        break;
    case 3:
        find.Findf();
        Choicef();
        break;
    default:

        std::cout << "Error!!! \n Do you thant enter again? yes-1 \n";
        std::cin >> m_choice;
        if (m_choice == 1)
            Menuf();
        if (m_choice != 1)
            break;
    }
}