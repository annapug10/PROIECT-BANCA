#include "cont.h"
using namespace std;
cont:: cont(const string& surname, const string& name, const string& iban, const int& balance,const string& type)
: surname(surname), name(name), iban(iban), balance(balance), type(type)
{
    cout << "CREEARE CONT :" << endl;
}

cont::~cont()
{
   cout << "STERGERE CONT:" <<endl;
}

void cont::set_surname(const string& surname)
{
    this->surname = surname;
}

void cont::set_name(const string& name)
{
    this->name = name;
}

void cont::set_balance(const int& balance)
{
    this->balance = balance;
}

void cont::set_type(const string& type)
{
    this->type = type;
}

const string cont::get_surname() const
{
    return surname;
}

const string cont::get_name() const
{
    return name;
}

const string cont::get_iban() const
{
    return iban;
}

const int cont::get_balance() const
{
    return balance;
}

const string cont::get_type() const
{
    return type;
}
