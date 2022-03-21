#include <iostream>
#include <fstream>
#include "InterFullName.h"

Menu::Menu(){}

Menu::Menu(int choice)
    : m_choice(choice){}

void Menu::Choicef()
{
    std::cout << "Will you whant enter one more time? : 1 , No : 2\n";
    std::cin >> m_choice;
    if (m_choice == 1)
        Menuf();
    
}

void Menu::Menuf(){

    Write write;
    Read read;
    Find find;
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

Write::Write(){}

Write::Write(std::string name, std::string surname)
        : m_name(name), m_surname(surname){}

void Write::Writef() {
    std::fstream fs;

    fs.open(file_txt, std::fstream::in | std::fstream::out | std::fstream::app);

    if (!fs.is_open())
        std::cout << "Ошибка открытия файла!\n";
    else {
        std::cout << "Фаил успешно открыт!\n";
        std::cout << "Enter name:\n";
        std::cin >> m_name;
        fs << m_name << m_surname;
        fs << " ";
        std::cout << "Enter surname:\n";
        std::cin >> m_surname;
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
        std::cout << "Ошибка открытия файла!\n";
    else {
        std::cout << "Фаил успешно открыт!\n";
        
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

        std::cout << "Ошибка открытия файла!\n";
    else {
   
        std::cout << "Фаил успешно открыт!\n";
        std::cout << "Введите первую букву имени для поиска : ";
        std::cin >> m_find[0];

        while (fs.get(m_ch[0]))
        {
            if (m_ch[0] == m_find[0])
            {
                if (!fs.eof()) {
                    fs.seekg(-1, std::ios::cur);
                    getline(fs, m_tempname);
                    
                    Printf(m_tempname);
                    break;     
                }
            }
        }
    }
    fs.close();
}