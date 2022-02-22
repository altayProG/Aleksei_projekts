#include <iostream>
#include <string>
//#include <cstring>
#include <fstream>
#include <Windows.h>
#include "InterFullName.h"
using namespace std;

int main()
{
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    
    InterFullName fullname;

    //fullname.Print();
    //WriteRead writeread;
    Write write(fullname);
    Read read(fullname);
    //WR wr;

    return 0;

}