#include <iostream>
#include <fstream>
#include "InterFullName.h"
using namespace std;



int Menu::Getm(m) {
    return ;
}

Menu::switch (Menu_enum) {
case 0:
    InterFullName();
}

InterFullName::InterFullName() {

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
    //cin.ignore(32767, '\n');
}

void InterFullName::Print() {

    cout << "\t\tName and surname: " << m_name << " " << m_surname << ".\n\n" << "\n" << "Age: " << m_age << ".\n"
        << "Weight: " << m_weight << " кг.\n" << "Phone number: " << m_phone_number << ".\n";
    cout << "---------------------------\n\n";
}

WriteRead::WriteRead() {
    string file_txt = "full_info.txt";

    fstream fs;
    fs.open(file_txt, fstream::in | fstream::out | fstream::app);

    if (!fs.is_open()) {
        cout << "file is't open" << endl;
    }
    else {
        cout << "file is open" << "\n";
        cout << "if you whant write ? Enter 1\n";
        cout << "if you whant read all message? Enter 2\n";

        string msg;
        int value;
        cin >> value;

        if (value == 1) {

            cout << "Enter your message\n";
            cin >> msg;
            fs << msg << "\n";

        }
        if (value == 2) {

            cout << "Read of file\n";

            while (!fs.eof()) {
                msg = "";
                getline(fs, msg);
                cout << msg << "\n";
            }
        }
    }
    fs.close();
}

Write::Write(InterFullName fullname) {

    //string file_txt = "full_info.txt";
    ofstream fout;

    fout.open(file_txt, ofstream::app);

    if (!fout.is_open()) {

        cout << "Ошибка открытия файла!\n";
    }
    else {

        cout << "Фаил успешно открыт!\n";

        fout.write((char*)&fullname, sizeof(InterFullName));
    }
    fout.close();
}

Read::Read(InterFullName fullname) {

    string file_txt = "full_info.txt";
    ifstream fin;

    fin.open(file_txt, ifstream::app);

    if (!fin.is_open()) {

        cout << "Ошибка открытия файла!\n";

    }
    else {

        cout << "Фаил успешно открыт!\n" << "\n";

        while (fin.read((char*)&fullname, sizeof(InterFullName))) {


            fullname.Print();
            //getline(fin, file_txt);
            //cout << "\n";
        }
    }
    fin.close();
}

WR::WR() {

    string file_txt = "full_info.txt";
    ofstream fout;
    fout.open(file_txt, ofstream::app);
    if (!fout.is_open()) {
        cout << "Ошибка открытия файла!\n";
    }
    else {
        cout << "Фаил успешно открыт!\n";
        cout << "Введите сообщение\n";
        string msg;
        cin >> msg;
        cin.ignore(32767, '\n');
        fout << msg;
        fout << "\n";
    }
    fout.close();

    ifstream fin;

    fin.open(file_txt, ifstream::app);
    if (!fin.is_open()) {
        cout << "Ошибка открытия файла!\n";
    }
    else {
        cout << "Фаил успешно открыт!\n";
        string str;
        while (!fin.eof()) {

            str = "";
            //getline(fin, str);

            fin >> str;
            cout << str << "\n";
        }

    }
    fin.close();
}

//OutputOverload::OutputOverload(InterFullName fullname) {
    
    //ostream& operator<<(ostream & os, const InterFullName & fullname) {
       // os << fullname
    //}
//}