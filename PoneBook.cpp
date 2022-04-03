#include <iostream>
#include <string>
#include <fstream>
#include "InterFullName.h"


int main()
 {
    setlocale(0, "");
    
    Write write;
    Read read;
    Find find;
    Del del;
    Print print;
    Menu menu(0);
    menu.Choicehuman(write);
    menu.Choicehuman(read);
    menu.Choicehuman(find);
    menu.Choicehuman(del);
    menu.Choicehuman(print);
    
    
    
    return 0;

}