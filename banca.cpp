#include "banca.h"
#include <cstdlib>
void clear_screen() {
    system("clear");
}
using namespace std;
banca::banca()
{

}

banca::~banca()
{

}

void banca::main_terminal()
{
 CSV.loaddatabase(database);
 CSV.loadibans(unique_ibans);
    char input;
    do
    {
        clear_screen();
        {cout << "===Bine ati venit la terminalul bancii ITSCHOOL.==="<<endl;
        cout<<"===VA ROG sa completati casutele de mai jos si urmaritit ce se va intampla!==="<<endl;
        cout<<"[1]Autentificare\n"<<endl;
        cout<<"[2]creeare cont nou\n"<<endl;
        cout<<"[3]Baza de date\n"<<endl;
        cout<<"[4]Iesire\n";}
        input = getch();
        if (isalpha(input))
            input = toupper(input);
        switch (input)
        {
        case '1':
            login();
            break;
        case '2':
            create_newaccount();
            break;
        case '3':
            get_database();
            break;
        case '4':
            return;
        default:
            break;
        }

    } while (true);
}

void banca::get_database()
{
    clear_screen();
    cout << "Numar de cont: " << database.size() << "\n";
    if (database.size() > 0)
for (const cont* cont : database)
cout << cont->get_surname() + " " + cont->get_name() + " " + cont->get_iban() + "\n";
    getch();}

void banca::create_newaccount()
{
    clear_screen();
   cout << "[1]CREEARE CONT NOU"<<endl;
   cout<<"[2]Inapoi\n";
    char input;
    do
    {
        input = getch();
        if (isalpha(input))
            input = toupper(input);
        switch (input)
        {
        case '1':
            break;
        case 'B':
            return;
        default:
            break;
        }
    } while (input != '1');


   cout << "CREEARE CONT:\n";

    cout << "NUMELE SI PRENUMELE DUMNEAVOASTRA VA ROG: ";
    string surname;
    cin >> surname;
    surname[0] = toupper(surname[0]);
    for (int i = 1; i < surname.size(); i++)
        surname[i] = tolower(surname[i]);

   string name;
   cin >> name;
    name[0] = toupper(name[0]);
    for (int i = 1; i < name.size(); i++)
        name[i] = tolower(name[i]);

    for (const cont* const cont : database)
        if (cont->get_surname() == surname && cont->get_name() == name)
        {
            cout << "Cont sub nume " + surname + " " + name + " exista deja.Va rog sa verificati numele sau prenumele .\n";
            cout << "Doriti să continuati crearea unui cont nou?\n";
            getch();
            return;
        }

    clear_screen();
    cout << "Cum vreti contul in:\n"<< endl;
    cout<<"[1]lei\n";
    string type;
    do
    {
        input = getch();
        switch (input)
        {
        case '1':
            type = "Lei";
            break;
           default:
            break;
        }
    } while (input != '1');

    clear_screen();

    string iban = generateiban();

    database.push_back(new cont(surname, name, iban, 0, type));
 cout << "NOUL CONT CU NUMELE SI PRENUMELE : " + surname + " " + name + " A FOST CREAT CU SUCCES.FELICTARI!\n";
        CSV.savedatabase(database);
cout << "NOUL CONT CU NUMELE SI PRENUMELE : " + surname + " " + name + " A FOST CREAT CU SUCCES.FELICTARI!\n";
    getch();
}

void banca::login()
{
    char input;
    do
    {
        do
        {
            clear_screen();
            cout << "[1] Vreti sa gasiti contul\n"<<endl;
            cout<<"[2]Inapoi\n";
            input = getch();
            if (isalpha(input))
                input = toupper(input);
            switch (input)
            {
            case '1':
                break;
            case 'B':
                return;
            default:
                break;
            }
        } while (input != '1');

        if (database.size() > 0)
        {
            clear_screen();
            cout << "NUMELE CONTULUI : ";
            string surname;
            cin >> surname;
            surname[0] = toupper(surname[0]);
            for (int i = 1; i < surname.size(); i++)
                surname[i] = tolower(surname[i]);

            string name;
            cin >> name;
            name[0] = toupper(name[0]);
            for (int i = 1; i < name.size(); i++)
                name[i] = tolower(name[i]);
cin.ignore(numeric_limits<streamsize>::max(), '\n');
string iban;
            cout << "IBANUL DUMEAVOASTRA ESTE : ";
            while (iban.size() < 4)
            {
               cin >> input;
                if (isdigit(input))
                    iban += input;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');


            bool match = false;
           for ( cont*  cont : database)
                if (cont->get_surname() == surname && cont->get_name() == name)
                {
                    match = true;
                    modifycont(cont);
                    break;
                }
                                if (match == false)
            {
                        clear_screen();
                        cout << "IBAN invalid, vă rugăm să încercați din nou.\n"<<endl;
                        cout<<"Mai incercati!";
                        getch();

                    }

                }


        else
        {
            clear_screen();
            cout << "Nu s-au gasit conturi inregistrate." <<endl;
            getch();
        }
    } while (true);
}
void banca::cont_balance(cont* const cont)
{

    int amount;
    char input;
    do
    {
        clear_screen();
        cout << "Soldul contului pentru " + cont->get_surname() + " " + cont->get_name() + ": " << to_string(cont->get_balance()) << endl;
        cout << "[1]Depozit\n"<<endl;
        cout<<"[2]Retragere\n"<<endl;
        cout<<"[3]Inapoi\n";
        input = getch();
        if (isalpha(input))
            input = toupper(input);
        switch (input)
        {
        case '1':
            cout << "Introduceți suma de depus: ";
            cin >> amount;
            cont->set_balance(cont->get_balance() + abs(amount));
            break;
        case '2':
            cout << "Introduceți suma de retras:";
            cin >> amount;
            cont->set_balance(cont->get_balance() - abs(amount));
            break;
        case 'B':
            return;
        default:
            break;
        }
    } while (true);
    CSV.savedatabase(database);}

void banca::modifycont(cont*  const cont)
{
    char input;
    do
    {
        clear_screen();
       cout << "Numele contului " + cont->get_surname() + " " + cont->get_name() + "\nIBAN: " + cont->get_iban() +
        "\ntipul contului : " + cont->get_type() + "\nsold: " << cont->get_balance() <<endl;
        cout<<"[1]Schimbati soldul\n"<<endl;
       cout<<"[2]Schimbarea prenumelui\n"<<endl;
         cout<<"[3]Schimbati numele\n"<<endl;
         cout <<"[4]Modificare tip cont\n"<<endl;
         cout<<"[5]Sterge contul\n"<<endl;
         cout<<"[6]Inapoi\n";
        input = getch();
        if (isalpha(input))
            input = toupper(input);
        switch (input)
        {
        case '1':
            cont_balance(cont);
            break;
        case '2':
            changesurname(cont);
            break;
        case '3':
            change2name(cont);
            break;
        case '4':
            change_type(cont);
            break;
        case '5':
            delete_cont(cont);
            return;
        case 'B':
            return;
        default:
            break;
        }
    } while (true);
}

void banca::changesurname(cont* const cont)
{
    clear_screen();
    string surname;
    cout << "Introduceti numele de familie nou: ";
    cin >> surname;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    surname[0] = toupper(surname[0]);
    for (int i = 1; i < surname.size(); i++)
        surname[i] = tolower(surname[i]);
   cont->set_surname(surname);

     CSV.savedatabase(database);
}
void banca :: change2name (cont* const cont)
{clear_screen();
   string name;
    cout << "Introduceți un nume nou: ";
    cin >> name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    name[0] = toupper(name[0]);
    for (int i = 1; i < name.size(); i++)
        name[i] = tolower(name[i]);
 cont->set_name(name);

CSV.savedatabase(database);
}

void banca::change_type(cont* const cont)
{
    clear_screen();
    cout << "Tipul contului:\n"<<endl;
    cout<<"[1]lei\n";
    string type;
    char case_4_input;
    do
    {
        case_4_input = getch();
        switch (case_4_input)
        {
        case '1':
            cont->set_type("Lei");
            break;
               default:
            break;
        }
    } while (case_4_input != '1');

  CSV.savedatabase(database);
}

void banca::delete_cont(cont* const cont)
{
    clear_screen();
cout << "Sunteti sigur ca doritisa stergeti acest cont?\n"<<endl;
cout<<"[1]DA!\n"<<endl;
cout<<"[2]NU!\n";
    switch (getch())
    {
    case 'y':
        for(int i = 0; i < database.size(); i++)
            if (cont == database[i])
            {
                clear_screen();
               cout << "CONT STERS:" + cont->get_surname() + " " + cont->get_name() + "!\n";
                  delete database[i];
                database.erase(database.begin() + i);
        CSV.savedatabase(database);
                getch();
            }
        return;
    default:
        break;
    }

}
const string banca::generateiban()
{

    if (unique_ibans.size() < 10000)
{   string generated_iban;
random_device random;
    mt19937 rng(random());
    uniform_int_distribution<mt19937::result_type> number(0,9);

    bool is_unique = true;
    do
    {
        for (int i = 0; i < 4; i++)
            generated_iban += to_string(number(rng));
        for (const string& iban : unique_ibans)
            if (generated_iban == iban)
             {
                    is_unique = false;
                    break;
                }

    } while(is_unique == false);

    unique_ibans.push_back(generated_iban);
        CSV.saveibans(unique_ibans);
    return generated_iban;
}
   else
        return "0";

}

void banca::clear_screen()
{
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}
