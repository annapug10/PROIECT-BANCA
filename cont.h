#ifndef ACCOUNT_H
#define ACCOUNT_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <random>
#include <memory>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <conio.h>
using namespace std;

class cont
{
public:
   cont(const string& surname, const string& name, const string& iban, const int& balance, const string& type);
    ~cont();


    void set_surname(const string& surname);
    void set_name(const string& name);
    void set_balance(const int& balance);
    void set_type(const string& type);


    const string get_surname() const;
    const string get_name() const;
    const string get_iban() const;
    const int get_balance() const;
    const string get_type() const;


private:
   string surname;
    string name;
    const string iban;
    int balance;
    string type;
};
#endif
