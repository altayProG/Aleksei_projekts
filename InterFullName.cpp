#include <iostream>
#include <fstream>
#include "InterFullName.h"
using namespace std;


MENU::MENU()

{
    Enter fullname;
    WRITE write;
    READ read;
    cout << "enter number menu 1, 2 \n 1 : enter and write\n 2 : read all info\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        fullname.Enter_name_surname();
        fullname.Enter_age_weight();
        fullname.Enter_phon_number();
        write.Write(fullname);
    case 2:
        read.Read(fullname);   
    default:
        break;
    }
    
}

string MENU::Enter::Enter_name_surname() {
    cout << "Inter Name: ";
    cin >> m_name;

    cout << "Inter surname: ";
    cin >> m_surname;
    return m_name, m_surname;
}

int MENU::Enter::Enter_age_weight() {

    cout << "Inter age: ";
    cin >> m_age;

    cout << "Inter weight: ";
    cin >> m_weight;

    return 0;
}

long long MENU::Enter::Enter_phon_number() {
    cout << "Enter pone number (eleven signs): ";
    cin >> m_phone_number;
    cout << "\n";

    return 0;
}

void MENU::Enter::Print() {

    cout << "\t\tName and surname: " << m_name << " " << m_surname << ".\n\n" << "\n" << "Age: " << m_age << ".\n"
        << "Weight: " << m_weight << ".\n" << "Phone number: " << m_phone_number << ".\n";
    cout << "---------------------------\n\n"; 
}

void MENU::WRITE::Write(Enter fullname) {

    fstream fs;
    fs.open(file_txt, fstream::in | fstream::out | fstream::app);

    if (!fs.is_open())
        cout << "Ошибка открытия файла!\n";
    else {
        
        cout << "Фаил успешно открыт!\n";

        fs.write((char*)&fullname, sizeof(Enter));
    }
    fs.close();

}

void MENU::READ::Read(Enter fullname) {

    fstream fs;
    fs.open(file_txt, fstream::in | fstream::out | fstream::app);

    if (!fs.is_open())

        cout << "Ошибка открытия файла!\n";
    else {

        cout << "Фаил успешно открыт!\n";
        
        while (fs.read((char*)&fullname, sizeof(Enter))) {

            fullname.Print();

            cout << "\n";
        }
    }
    fs.close();

}