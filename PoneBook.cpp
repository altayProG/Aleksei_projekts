#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

class FULLNAME
{

public:

    string name = " ";
    long long pone_number = 0;

    FULLNAME() {}

    FULLNAME(string name, long long pone_number) {

        this->name = name;
        this->pone_number = pone_number;
    }

    void Print() {

        cout << "name: " << name << endl << "Pone number: " << pone_number << endl;
    }
};

class WRITE :public FULLNAME
{

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
            fout.write((char*)&fullname, sizeof(FULLNAME));
        }
        fout.close();
    }
};

int main()
{
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    WRITE write;
    long long a = 0;
    string f;
    cin >> f >> a;
    FULLNAME fullname(f, a);
    fullname.Print();

    return 0;

}