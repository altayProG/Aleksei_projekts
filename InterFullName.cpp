#include <iostream>
#include <fstream>
#include "InterFullName.h"
using namespace std;


MENU::MENU()

{
    INTERFULLNAME fullname;
    WRITE write;
    READ read;
    cout << "enter number menu 1, 2, 3 \n 1 : enter and write\n 2 : read all info";
    cin >> choice;
    switch (choice)
    {
    case 1:
        fullname.INTERFULLNAMEf();
        write.WRITEf(fullname);
    case 2:
        read.READf(fullname);
    case 3:
        
    default:
        break;
    }
    
}

string MENU::INTERFULLNAME::INTERFULLNAMEff() {
    cout << "Inter Name: ";
    cin >> m_name;

    cout << "Inter surname: ";
    cin >> m_surname;
    return m_name, m_surname;
}

long long MENU::INTERFULLNAME::INTERFULLNAMEfff() {
    cout << "Enter pone number (eleven signs): ";
    cin >> m_phone_number;
    cout << "\n";
    return 0;
}

int MENU::INTERFULLNAME::INTERFULLNAMEf() {

    cout << "Inter age: ";
    cin >> m_age;

    cout << "Inter weight: ";
    cin >> m_weight;
 
    return 0;
}

void MENU::INTERFULLNAME::Print() {

    cout << "\t\tName and surname: " << m_name << " " << m_surname << ".\n\n" << "\n" << "Age: " << m_age << ".\n"
        << "Weight: " << m_weight << ".\n" << "Phone number: " << m_phone_number << ".\n";
    cout << "---------------------------\n\n"; //int-ы выводятся не корректно возможно, нужно приведение типов
}

void MENU::WRITE::WRITEf(INTERFULLNAME fullname) {

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

void MENU::READ::READf(INTERFULLNAME fullname) {

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