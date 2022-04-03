#pragma once
#include <string>

class Database
{
public:
    void virtual Writehuman() = 0;
    void virtual Readhuman() = 0;
    void virtual Findhuman() = 0;
    void virtual Delhuman() = 0;
    void virtual Printhuman(std::string m_tempname) = 0;
    
};

class Write : public Database
{
private:
    std::string m_file_txt = "full_info.txt";
    std::string m_del_file_txt = "del_file.txt";
    std::fstream fs;
    std::fstream fdel;
    std::string m_find;
    std::string m_name;
    std::string m_surname;
    std::string m_tempname;
    
public:
    
    void Writehuman()override;
    void Readhuman()override;
    void Findhuman()override;
    void Delhuman()override;
    void Printhuman(std::string m_tempname)override;

};

class Read : public Write
{
private:
    std::string m_file_txt = "full_info.txt";
    std::fstream fs;
    std::string m_tempname;
public:
   
    void Writehuman()override;
    void Readhuman()override;
    void Findhuman()override;
    void Delhuman()override;
    void Printhuman(std::string m_tempname)override;
};

class Find : public Read
{
private:
    std::string file_txt = "full_info.txt";
    std::fstream fs;
    std::string m_tempname;
    std::string m_find;
    
public:
    
    void Writehuman()override;
    void Readhuman()override;
    void Findhuman()override;
    void Delhuman()override;
    void Printhuman(std::string m_tempname)override;

};

class Del : public Find
{
private:
    std::string m_file_txt = "full_info.txt";
    std::string m_del_file_txt = "del_file.txt";
    std::fstream fs;
    std::fstream fdel;
    std::string m_tempname;
    std::string m_find;
public:
   
    void Writehuman()override;
    void Readhuman()override;
    void Findhuman()override;
    void Delhuman()override;
    void Printhuman(std::string m_tempname)override;
};

class Menu /*: public Del*/
{
private:
    int m_choice = 0;
public:
    Menu(int m_choice);
    void Choicehuman(Database& database);
    
    
  
};

class Print : public Del
{
public:
    
    void Writehuman()override;
    void Readhuman()override;
    void Findhuman()override;
    void Delhuman()override;
    void Printhuman(std::string m_tempname)override;
};



