#ifndef CSV_H
#define CSV_H
#include "cont.h"
using namespace std;
class CSV
{
public:
    CSV();
    ~CSV();


    void savedatabase(const vector <cont*>& database);
    void loaddatabase(vector <cont*>& database);

    void saveibans(const vector <string>& unique_ibans);
    void loadibans(vector <string>& unique_ibans);

private:
};

#endif
