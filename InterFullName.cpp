#include <iostream>
#include <fstream>
#include "InterFullName.h"
using namespace std;


Menu::Menu()
{
    Enterfullname fullname;
    Write write;
    Read read;
    Find find;
    
    cout << "enter number menu 1, 2, 3.\n " 
         << "1 : enter and write\n "
         << "2 : read all info\n "
         << "3 : find one\n";
    cin >> choice;

    switch (choice)
    {
    case 1:

        fullname.Enter_name_surname();
        fullname.Enter_age_weight();
        fullname.Enter_phon_number();
        write.Writef(fullname);
        break;

    case 2:

        read.Readf(fullname);
        break;

    case 3:

        find.Findf(fullname);
        break;

    default:

        cout << "Error!!! \n Do you thant enter again? yes-1 \n";
        cin >> choice;

        if (choice == 1)
            Menu();
        if (choice != 1)
            break;
        
            
    }
    
}

string Menu::Enterfullname::Enter_name_surname() {
    cout << "Inter Name: ";
    cin >> m_name;

    cout << "Inter surname: ";
    cin >> m_surname;
    return m_name, m_surname;
}

int Menu::Enterfullname::Enter_age_weight() {

    cout << "Inter age: ";
    cin >> m_age;

    cout << "Inter weight: ";
    cin >> m_weight;

    return 0;
}

long long Menu::Enterfullname::Enter_phon_number() {
    cout << "Enter pone number (eleven signs): ";
    cin >> m_phone_number;
    cout << "\n";

    return 0;
}

void Menu::Enterfullname::Print() {

    cout << "\t\tName and surname: " << m_name << " " << m_surname << ".\n\n" << "\n" << "Age: " << m_age << ".\n"
        << "Weight: " << m_weight << ".\n" << "Phone number: " << m_phone_number << ".\n";
    cout << "---------------------------\n\n"; 
}

void Menu::Write::Writef(Enterfullname fullname) {

    fstream fs;
    fs.open(file_txt, fstream::in | fstream::out | fstream::app);

    if (!fs.is_open())
        cout << "Ошибка открытия файла!\n";
    else {
        
        cout << "Фаил успешно открыт!\n";

        fs.write((char*)&fullname, sizeof(Enterfullname));
    }
    fs.close();

}

void Menu::Read::Readf(Enterfullname fullname) {

    fstream fs;
    fs.open(file_txt, fstream::in | fstream::out | fstream::app);

    if (!fs.is_open())

        cout << "Ошибка открытия файла!\n";
    else {

        cout << "Фаил успешно открыт!\n";
        
        while (fs.read((char*)&fullname, sizeof(Enterfullname))) {

            fullname.Print();

            cout << "\n";
        }
    }
    fs.close();

}

void Menu::Find::Findf(Enterfullname fullname)
{
    fstream fs;
    fs.open(file_txt, fstream::in | fstream::out | fstream::app);

    if (!fs.is_open())

        cout << "Ошибка открытия файла!\n";
    else {
        char find_letter;
        char ch;
        cout << "Фаил успешно открыт!\n";
        cout << "Введите первую букву имени для поиска : ";
        cin >> find_letter;
        while (fs.get(ch)) {

            if (ch == find_letter)
            {
                while (fs.read((char*)&fullname, sizeof(Enterfullname))) {//ошибка!!!

                    fullname.Print();

                    cout << "\n";
                }
            }
            
        }
    }
    fs.close();
}