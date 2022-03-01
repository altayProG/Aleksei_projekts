#include <iostream>
#include <fstream>
#include "InterFullName.h"
using namespace std;

MENU::MENU() {
    cout << "Inter 1 or 2 : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        INTERFULLNAME();
    case 2:
        WRITE(INTERFULLNAME fullname);
    default:
        break;
    }
}

INTERFULLNAME::INTERFULLNAME() {

    cout << "Inter Name: ";
    cin >> m_name;

    cout << "Inter surname: ";
    cin >> m_surname;

    cout << "Inter age: ";
    cin >> m_age;

    cout << "Inter weight: ";
    cin >> m_weight;

    cout << "Enter pone number (eleven signs): ";
    cin >> m_phone_number;
    cout << "\n";

   
}

void INTERFULLNAME::Print() {

    cout << "\t\tName and surname: " << m_name << " " << m_surname << ".\n\n" << "\n" << "Age: " << m_age << ".\n"
        << "Weight: " << m_weight << ".\n" << "Phone number: " << m_phone_number << ".\n";
    cout << "---------------------------\n\n";
}

WRITE::WRITE(INTERFULLNAME fullname) {

    fstream fs;
    fs.open(file_txt, fstream::in | fstream::out | fstream::app);

    if (!fs.is_open()) 
        cout << "Ошибка открытия файла!\n";
    else {

        cout << "Фаил успешно открыт!\n";

        fs.write((char*)&fullname, sizeof(INTERFULLNAME));
    }
    fs.close();
    
}

READ::READ(INTERFULLNAME fullname) {

    fstream fs;
    fs.open(file_txt, fstream::in | fstream::out | fstream::app);

    if (!fs.is_open()) 

        cout << "Ошибка открытия файла!\n";
    else {

        cout << "Фаил успешно открыт!\n";

        while (fs.read((char*)&fullname, sizeof(INTERFULLNAME))) {

            fullname.Print();
            
            cout << "\n";
        }
    }
    fs.close();
    
}