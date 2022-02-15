#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <Windows.h>
//#include "Header.h"
using namespace std;

class INTERFULLNAME
{

private:

    string name = " ";
    long long pone_number = 0;

public:



    INTERFULLNAME(string name, long long pone_number) {

        this->name = name;
        this->pone_number = pone_number;

    }

    INTERFULLNAME() {

        cout << "Inter Name and Surname: \n";
        cin >> name;
        cout << "Enter pone number (eleven signs): \n";
        cin >> pone_number;

        if (sizeof(pone_number) != 8) {

            cout << "It's number error!\n";
            cout << "Do you want to enter number from beginning?(yes(1) and no(2))\n";

            int yes_no = 0;
            cin >> yes_no;

            switch (yes_no)
            {
            case 1:
                INTERFULLNAME();
            case 2:
                break;
            }


        }
    }

    void Print() {

        cout << "name: " << name << endl << "Pone number: " << pone_number << endl;
    }

};

class WRITE {
private:

    string file_txt = "full_info.txt";

public:

    WRITE() {

        string file_txt = "full_info.txt";
        ofstream fout;

        fout.open(file_txt, ofstream::app);

        if (!fout.is_open()) {
            cout << "Ошибка открытия файла!\n";
        }
        else {
            cout << "Фаил успешно открыт!\n";
            fout.write((char*)&file_txt, sizeof(INTERFULLNAME));
        }
        fout.close();
    }
};


int main()
{
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    INTERFULLNAME fullname;
    fullname.Print();
    WRITE write;

    //const int size = 3;

    //INTERFULLNAME arr[size];
    //arr[0] = fullname;
    //WRITE write;//(arr[size]);
 
    return 0;

}