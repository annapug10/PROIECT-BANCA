#include "CSV.h"
using namespace std;
CSV::CSV()
{

}
CSV::~CSV()
{

}

void CSV::savedatabase(const vector <cont*>& database)
{
    fstream file;
    file.open("conturile.CSV", ios::out);

    for (const cont* cont:database)
    {
        file <<cont->get_surname() + ","
        + cont->get_name() + "," + cont->get_iban() + ","
        +  to_string(cont->get_balance()) + ","
        + cont->get_type() + "\n";
    }
    file.close();
}

void CSV::loaddatabase(vector <cont*>& database)
{
    fstream file;

     file.open("conturile.csv", ios::out);

    vector <string> data;
    string row, row_element;
    while (getline(file, row))
    {
        stringstream stream(row);
        while(getline(stream, row_element, ','))
        {
            data.push_back(row_element);
        }
    }

    string surname, name, iban, balance, type;
    int x = 0;
    for (int i = 0; i < data.size() / 5; i++)
    {
        database.push_back(new cont(data[0 + x], data[1 + x], data[2 + x], stoi(data[3 + x]), data[4 + x]));
        x += 5;
    }

    file.close();
}

void CSV::saveibans(const vector <string>& unique_ibans)
{
    fstream file;
    file.open("ibanurile.CSV", ios::out);

    for (const string& iban : unique_ibans)
    {
        file << iban + "\n";
    }

    file.close();
}

void CSV::loadibans(vector <string>& unique_ibans)
{
    fstream file;

    file.open("ibanurile.CSV", ios::in);

    vector <string> data;
    string iban;
    while (getline(file, iban))
        data.push_back(iban);

    for (int i = 0; i < data.size(); i++)
        unique_ibans.push_back(data[i]);

    file.close();
}
