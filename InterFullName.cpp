#include <iostream>
#include <fstream>
#include "InterFullName.h"
using namespace std;

InterFullName::InterFullName() {

    cout << "Inter Name and Surname: \n";
    cin >> name;
    cin.ignore(32767, '\n');
    cout << "Enter pone number (eleven signs): \n";
    cin >> pone_number;
    cin.ignore(32767, '\n');
}

void InterFullName::Print() {

    cout << "name: " << name << endl << "Pone number: " << pone_number << "\n";
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

        cout << "Фаил успешно открыт!\n";

        while (fin.read((char*)&fullname, sizeof(InterFullName))) {


            fullname.Print();
            //getline(fin, file_txt);
            cout << "\n";
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