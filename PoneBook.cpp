#include <iostream>
#include <string>
//#include <cstring>
#include <fstream>
#include <Windows.h>
#include "InterFullName.h"


int main()
 {
    setlocale(0, "");

   /* SetConsoleCP(1251);
    SetConsoleOutputCP(1251);*/
    Write write;
    Read read;
    Find find;
    Menu menu{ 0 ,write, read, find };
    menu.Menuf();
    
    return 0;

}