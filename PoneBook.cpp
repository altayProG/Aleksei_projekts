#include <iostream>
#include <string>
//#include <cstring>
#include <fstream>
#include <Windows.h>
//#include "Header.h"
using namespace std;

class InterFullName
{

private:

    string name;
    long long pone_number;

public:
    

    InterFullName() {

        cout << "Inter Name and Surname: \n";
        cin >> name;
        cin.ignore(32767, '\n');
        cout << "Enter pone number (eleven signs): \n";
        cin >> pone_number;
        cin.ignore(32767, '\n');
        long long a;
        
    }

    void Print() {

        cout << "name: " << name << endl << "Pone number: " << pone_number << endl;
    }

};



class Write {
private:

    string file_txt = "full_info.txt";

public:
    

    Write(InterFullName fullname) {

        string file_txt = "full_info.txt";
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
};

class Read {
private:

    string file_txt = "full_info.txt";

public:
    
    Read(InterFullName fullname)  {

        string file_txt = "full_info.txt";
        ifstream fin;

        fin.open(file_txt, ifstream::app);

        if (!fin.is_open()) {

            cout << "Ошибка открытия файла!\n";
        }
        else {
        
            cout << "Фаил успешно открыт!\n";
            
            while (fin.read((char*)&fullname, sizeof(InterFullName))) {
                //getline(fin, file_txt);
                fullname.Print();
                cout << endl;
            }
        }
        fin.close();
    }
};
int main()
{
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    InterFullName fullname;
    //fullname.Print();
    Write write(fullname);
    Read read(fullname);

    return 0;

}