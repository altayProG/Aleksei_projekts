#include <iostream>
#include <fstream>
#include "InterFullName.h"

Menu::Menu(){}

Menu::Menu(int choice)
    : m_choice(choice){}

void Menu::Choicef()
{
    std::cout << "Will you whant enter one more time? : 1 , No : 2\n";
    std::cin >> m_choice;
    if (m_choice == 1)
        Menuf();
    
}

void Menu::exit(){}

void Menu::Menuf()
{
    Enterfullname fullname;
    Write write;
    Read read;
    //Find find;
    std::cout << "enter number menu 1, 2, 3.\n "
        << "1 : enter and write\n "
        << "2 : read all info\n "
        << "3 : find one\n";
    std::cin >> m_choice;

    switch (m_choice)
    {
    case 1:
        fullname.Enter_name_surname();
        fullname.Enter_age_weight();
        fullname.Enter_phon_number();
        write.Writef(fullname);
        Choicef();
        break;

    case 2:
        read.Readf(fullname);
        Choicef();
        break;

    case 3:
        //find.Findf(fullname);
        Choicef();
        break;

    default:

        std::cout << "Error!!! \n Do you thant enter again? yes-1 \n";
        std::cin >> m_choice;
        if (m_choice == 1)
            Menuf();
            if (m_choice != 1)
                break;
    }
}

void Enterfullname::Printf()
{
    std::cout << "\t\tName and surname: " << m_name << " " << m_surname << ".\n\n" << "\n" << "Age: " << m_age << ".\n"
        << "Weight: " << m_weight << ".\n" << "Phone number: " << m_phone_number << ".\n";
    std::cout << "---------------------------\n\n";
}

Enterfullname::Enterfullname() {}

Enterfullname::Enterfullname(std::string name, std::string surname, int weight, int age, long long phone_number)

    : m_name(name), m_surname(surname), m_weight(weight),
    m_age(age), m_phone_number(phone_number){}

std::string Enterfullname::Enter_name_surname() {
    std::cout << "Inter Name: ";
    std::cin >> m_name;

    std::cout << "Inter surname: ";
    std::cin >> m_surname;
    return m_name, m_surname;
}


int Enterfullname::Enter_age_weight() {

    std::cout << "Inter age: ";
    std::cin >> m_age;

    std::cout << "Inter weight: ";
    std::cin >> m_weight;

    return 0;
}

long long Enterfullname::Enter_phon_number() {
    std::cout << "Enter pone number (eleven signs): ";
    std::cin >> m_phone_number;
    std::cout << "\n";

    return 0;
}


void Write::Writef(Enterfullname &fullname) {

    std::fstream fs;
    fs.open(file_txt, std::fstream::in | std::fstream::out | std::fstream::app);

    if (!fs.is_open())
        std::cout << "Ошибка открытия файла!\n";
    else {
        
        std::cout << "Фаил успешно открыт!\n";

        fs.write((char*)&fullname, sizeof(Enterfullname));
    }
    fs.close();

}

void Read::Readf(Enterfullname &fullname) {
   
    fs.open(file_txt, std::fstream::in | std::fstream::out | std::fstream::app);

    if (!fs.is_open())

        std::cout << "Ошибка открытия файла!\n";
    else {

        std::cout << "Фаил успешно открыт!\n";
        
        while (fs.read((char*)&fullname, sizeof(Enterfullname))) {

            fullname.Printf();

            std::cout << "\n";
        }
    }
    fs.close();

}

//Find::Find(){}
//
//Find::Find(string find_letter, char ch)
//    : m_find_letter(find_letter), m_ch(ch){}
//
//void Find::Findf(Enterfullname &fullname)
//{
//    fs.open(file_txt, fstream::in | fstream::out | fstream::app);
//
//    if (!fs.is_open())
//
//        cout << "Ошибка открытия файла!\n";
//    else {
//   
//        cout << "Фаил успешно открыт!\n";
//        cout << "Введите первую букву имени для поиска : ";
//        cin >> m_find_letter;
//        //fs.seekg(5);
//        getline(fs, m_find_letter);
//        cout << m_find_letter << "\n";
//        //fullname.Printf();
//
//    }
//    fs.close();
//}