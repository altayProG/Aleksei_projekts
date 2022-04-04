#include <iostream>
#include <string>
#include <fstream>
#include "InterFullName.h"


int main()
{
    setlocale(0, "");
    Print print;
    Write write;
    Read read(" ", "full_info.txt", print);
    Find find(" ", "full_info.txt", print);
    Del del(" ", "full_info.txt", print);
    Menu menu{ 0 ,write, read, find, del };
    menu.Menuf();

    return 0;

}