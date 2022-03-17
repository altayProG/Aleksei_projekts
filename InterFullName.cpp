#include <iostream>
#include <fstream>
#include "InterFullName.h"
using namespace std;

Menu::Menu(){}

Menu::Menu(int choice)
    : m_choice(choice){}

void Menu::setMenu(int choice) {
    m_choice = choice;
}

int Menu::getMenu() {
    return m_choice;
}

void Menu::Menuf()
{
    Enterfullname fullname;
    Write write;
    Read read;
    cout << "enter number menu 1, 2, 3.\n "
        << "1 : enter and write\n "
        << "2 : read all info\n "
        << "3 : find one\n";
    cin >> m_choice;

    switch (m_choice)
    {
    case 1:

        fullname.Enter_name_surname();
        fullname.Enter_age_weight();
        fullname.Enter_phon_number();
        write.Writef(fullname);

        cout << "Will you whant enter one more time? : 1 , No : 2\n";
        cin >> m_choice;
        if (m_choice == 1)
        {
            Menuf();
        }
        break;

    case 2:

        read.Readf(fullname);
        break;

    case 3:

        //find.Findf(fullname);
        break;

    default:

        cout << "Error!!! \n Do you thant enter again? yes-1 \n";
        cin >> m_choice;

        if (m_choice == 1)
            Menuf();
            if (m_choice != 1)
                break;


    }
}

Enterfullname::Enterfullname() {}

Enterfullname::Enterfullname(string name, string surname, int weight, int age, long long phone_number)

    : m_name(name), m_surname(surname), m_weight(weight),
    m_age(age), m_phone_number(phone_number){}

void Enterfullname::setName_surname(string name, string surname)
{
    m_name = name;
    m_surname = surname;
}

string Enterfullname::getName_surname()
{
    return m_name, m_surname;
}

string Enterfullname::Enter_name_surname() {
    cout << "Inter Name: ";
    cin >> m_name;

    cout << "Inter surname: ";
    cin >> m_surname;
    return m_name, m_surname;
}

void Enterfullname::setAge_weight(int weight, int age)
{
    m_weight = weight;
    m_age = age;
}

int Enterfullname::getAge_weight()
{
    return m_weight, m_age;
}

void Enterfullname::setPhon_number(long long phone_number)
{
    m_phone_number = phone_number;
}

long long Enterfullname::getPhon_number()
{
    return m_phone_number;
}

int Enterfullname::Enter_age_weight() {

    cout << "Inter age: ";
    cin >> m_age;

    cout << "Inter weight: ";
    cin >> m_weight;

    return 0;
}

long long Enterfullname::Enter_phon_number() {
    cout << "Enter pone number (eleven signs): ";
    cin >> m_phone_number;
    cout << "\n";

    return 0;
}

void Enterfullname::Print() {

    cout << "\t\tName and surname: " << m_name << " " << m_surname << ".\n\n" << "\n" << "Age: " << m_age << ".\n"
        << "Weight: " << m_weight << ".\n" << "Phone number: " << m_phone_number << ".\n";
    cout << "---------------------------\n\n"; 
}

void Write::Writef(Enterfullname &fullname) {

    fstream fs;
    fs.open(file_txt, fstream::in | fstream::out | fstream::app);

    if (!fs.is_open())
        cout << "Ошибка открытия файла!\n";
    else {
        
        cout << "Фаил успешно открыт!\n";

        fs.write((char*)&fullname, sizeof(Enterfullname));
    }
    fs.close();

}

void Read::Readf(Enterfullname &fullname) {

    fs.open(file_txt, fstream::in | fstream::out | fstream::app);

    if (!fs.is_open())

        cout << "Ошибка открытия файла!\n";
    else {

        cout << "Фаил успешно открыт!\n";
        
        while (fs.read((char*)&fullname, sizeof(Enterfullname))) {

            fullname.Print();

            cout << "\n";
        }
    }
    fs.close();

}

//void Find::Findf(Enterfullname fullname)
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
//        cin >> find_letter;
//        while (fs.get(ch)) {
//
//            if (ch == find_letter)//выводит с нужного символа но!
//            {
//                while (fs.read((char*)&fullname, fs. eof())) {
//                    string str;
//                    fs >> str;
//                    fullname.Print();//инициализация в принт остается первичной 
//                    //вопрос? как считать из файла нужную часть записанного обьектa?
//                                     
//                    
//                }
//            }
//            
//        }
//    }
//    fs.close();
//}