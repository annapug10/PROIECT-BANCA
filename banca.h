#ifndef banca_H
#define banca_H
#include "CSV.h"
using namespace std;
class banca
{
public:
    banca();
    ~banca();

    void main_terminal();//Ecranul principal al aplicației utilizate pentru a naviga în sistem

    void get_database();//afișează numărul de conturi din baza de date, precum și detalii despre toate conturile existente

    void create_newaccount(); //adaugă un nou obiect cont în baza de date

    void login(); //conectați-vă la un cont existent

    void cont_balance(cont* const cont); //modifică soldul unui cont

    void modifycont(cont* const cont); //meniu pentru modificarea contului existent

    void changesurname(cont* const contt); //schimbă numele de familie al unui cont

    void change2name(cont* const cont); //schimbă numele unui cont

    void change_type(cont* const cont); //modifică tipul unui cont

    void delete_cont(cont* const cont);//șterge contul adresei potrivite

    const string generateiban(); //generează un cod iban unic

    void clear_screen(); //șterește consola
private:
    vector <cont*> database;
  vector <string> unique_ibans;
    CSV CSV;
};

#endif
