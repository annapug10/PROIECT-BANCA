# PROIECT-BANCA
Rezumat :
ACEST  COD REPREZINTA  IMPLEMENTAREA UNEI APLICATII DE TIP TERMINAL DE LA O BANCA ,ITSchoolBank.
În funcție de opțiunea selectată de utilizator din meniul principal, acesta poate să se autentifice, să creeze un cont nou sau să afișeze baza de date cu toate conturile existente.
Codul acesta  implementează metodele și constructorii necesari pentru a crea și manipula un obiect de tip cont bancar.

Banca Proiect-CERINTA 
ITSchoolBank
Creeati o applicatie ce poate simula un terminal de la o banca ce poate fi folosita de catre
un angajat al bancii.

1. O clasa cont bancar ce trebuie sa aibe atribute precum nume,prenume, sold, tip de cont (valuta sau lei) IBAN
Un cont trebuie neaparat sa aibe un nume,prenume si un IBAN care trebuie sa fie unic

2.in maine se afla terminalul principal al bancii in care trebuie sa avem urmatoarele optiunii
   2.1 numar de conturi --> ce ne da numarul de conturi inregistrate in banca
   2.2 creare cont --> cu aceasta optiune se poate crea un cont nou 
        2.2.1 --> ar trebui un scrren diferit si un set de optiuni in care
        operatorul bancii sa introduca datele pentru crearea contului.(trebuie ca aceasta procedura sa verifice daca exista deja contul ce 
        se doreste creat iar daca da sa anunte opreatorul)
        2.2.2 --> o optiune de return la main screen ( ecranul cu optiunie principale )
   2.3 O optiune de modificare cont-> in care operatorul poate sa modifice date despre cont(ex schimbare nume, schimbare sume etc)
   2.4 O optiune prin care un cont se poate sterge din sistemul bancii
   2.5 O optiune prin care un cont poate sa extraga sume - > vrei sa adaugi sau sa extragi o suma de bani
   2.6 O optiune prin care un cont sa vada care este suma din cont
        Trebuie cautat contul intordus iar daca exista se poate vizualiza
        Daca nu exista putem incepe o procedura de creare cont

3. Un sistem in care putem sa salvam datele acestea intr-un fisier local (CSV file)
