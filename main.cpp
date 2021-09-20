#include <bits/stdc++.h>

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <Windows.h>
#include <fstream>

using namespace std;

typedef struct
    {
    char nume[30];
    char prenume [30];
    char numar [20];
    char email [130];
    char varsta [10];
    char adresa[100];

    }Contact;

    Contact agenda [500];
    int contor=1;

bool comp(Contact x, Contact y)
{
    int numeDif = strcmp(x.nume, y.nume);
    int prenumeDif = strcmp(x.prenume, y.prenume);

    if (numeDif < 0) return true;
    else if (numeDif == 0 && prenumeDif < 0) return true;

    return false;
}

void Ordonare_Contacte()
{
    sort(agenda + 1, agenda + contor+1, comp);
}


void readFromFile()
{
    FILE *fp;
    if((fp = fopen("agenda_telefonica.db", "rb")) == NULL)
    {

        return;
    }


    if(fread(&contor, sizeof(contor), 1, fp) != 1)
    {

        return;
    }

    if(fread(agenda, sizeof(agenda), 1, fp) != 1)
    {

        return;
    }

}

void saveToFile()
{
    FILE *fp;
    if( (fp = fopen("agenda_telefonica.db", "wb")) == NULL )
    {
        return;
    }

    if (fwrite(&contor, sizeof(contor), 1, fp) != 1 )

    {
        return;
    }

    if(fwrite(agenda, sizeof(agenda), 1, fp) != 1)
    {
        return;
    }

}

void SetColor (unsigned short color)
{
    HANDLE hcon = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}

void TextAgenda ()
{
    SetColor (11);
    cout<<"                        ********   **********   *********  **     **   *****      ******** "<<endl;
    cout<<"                        **    **   **           **         ***    **   **   **    **    ** "<<endl;
    cout<<"                        **    **   **           **         ** *   **   **    **   **    ** "<<endl;
    cout<<"                        ********   **     ****  *******    **  *  **   **     **  ******** "<<endl;
    cout<<"                        **    **   **      **   **         **   * **   **    **   **    ** "<<endl;
    cout<<"                        **    **   **      **   **         **    ***   **   **    **    ** "<<endl;
    cout<<"                        **    **   **********   *********  **     **   *****      **    ** "<<endl<<endl<<endl;


    SetColor (15);
}

void TextTelefonica ()
{
    SetColor (13);

    cout<<"   **********   *********   **          *********   **********   ********    **     **    **    *********   ******** "<<endl;
    cout<<"       **       **          **          **          **           **    **    ***    **    **    **          **    ** "<<endl;
    cout<<"       **       **          **          **          **           **    **    ** *   **    **    **          **    ** "<<endl;
    cout<<"       **       *******     **          *******     ****         **    **    **  *  **    **    **          ******** "<<endl;
    cout<<"       **       **          **          **          **           **    **    **   * **    **    **          **    ** "<<endl;
    cout<<"       **       **          **          **          **           **    **    **    ***    **    **          **    ** "<<endl;
    cout<<"       **       *********   *********   *********   **           ********    **     **    **    *********   **    ** "<<endl<<endl<<endl;
    SetColor (15);
}

void Parola ()
{
    int ok=0;
    string parola;
    SetColor (13);
    cin>>parola;
    SetColor(11);
    if(parola!="abracadabra")
        ok++;
        if (ok==1)
            {
                cout<<"Parola este incorecta. Mai aveti 2 incercari:";
                SetColor (13);
                cin>>parola;
                if(parola!="abracadabra")
                    ok++;
                    SetColor(11);
            }

        if (ok==2)
            {
                cout<<"Parola este incorecta. Mai aveti o incercare:";
                SetColor (13);
                cin>>parola;
                if(parola!="abracadabra")
                    ok++;
                    SetColor(11);
            }

        if (ok==3)
             {
                 cout<<"Ne pare rau. Nu puteti accesa meniul agendei."<<endl;
                 exit ( 0 );
             }

}

void TextMeniu ()
{
    SetColor (11);
    cout<<endl<<"Felicitari! Ati accesat meniul agendei telefonice."<<endl;
    SetColor (10);
    cout<<endl;
    cout<<endl;
    cout<<" ----------------------------------------------------------------------------------------------------------------------- "<<endl;
    cout<<" -----------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
    cout<<"                                  #       #   # # # #   #     #   #   #     # "<<endl;
    cout<<"                                  # #   # #   #         # #   #       #     # "<<endl;
    cout<<"                                  #   #   #   # # #     #  #  #   #   #     # "<<endl;
    cout<<"                                  #       #   #         #   # #   #   #     # "<<endl;
    cout<<"                                  #       #   # # # #   #     #   #   # # # # "<<endl<<endl;
    cout<<" -----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<" -----------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
    SetColor (10);
    cout<<"                                       1.Afiseaza contactele (Complete)."<<endl;
    cout<<"                                     2.Afiseaza contactele (Nume/Prenume)."<<endl;
    cout<<"                                      3.Cauta o persoana in contacte."<<endl;
    cout<<"                                           4.Adauga un contact."<<endl;
    cout<<"                                           5.Elimina un contact."<<endl;
    cout<<"                               6.Editeaza datele de contact ale unei persoane."<<endl;
    cout<<"                               7.Afiseaza numarul de contacte din agenda."<<endl;
    cout<<"                                                  8.Iesire."<<endl<<endl<<endl;
}



void Adauga ()
{


    if(contor == 501)
    {
        cout<<"Agenda este plina."<<endl;
        return;
    }
    Contact c1;
    SetColor(11);
    cout<<"Nume: ";
    SetColor (13);
    cin.ignore();
    cin.get(c1.nume,30);
    SetColor(11);
    cout<<"Prenume: ";
    SetColor (13);
    cin>>c1.prenume;
    SetColor(11);
    cout<<"Numar de telefon: ";
    SetColor (13);
    cin>>c1.numar;
    SetColor(11);
    cout<<"Adresa de email: ";
    SetColor (13);
    cin>>c1.email;
    SetColor(11);
    cout<<"Varsta: ";
    SetColor (13);
    cin.ignore();
    cin.get(c1.varsta, 10);
    SetColor(11);
    cout<<"Adresa: ";
    SetColor (13);
    cin.ignore();
    cin.get(c1.adresa,100);
    agenda[contor]=c1;
    Ordonare_Contacte();

    contor++;
    SetColor(10);
    cout<<"Contact adaugat cu succes."<<endl<<endl;

}

void AfisareContacte ()
{
    if(contor == 1)
    {
        cout<<"Agenda este goala."<<endl<<endl;
        return;
    }
    else
    {
    SetColor(10);
    cout<<endl<<"Contactele existente in agenda sunt:"<<endl<<endl;
    int i;
    for(i=1; i<contor; i++)
    {
        cout<<'*'<<" Nume: "<<agenda[i].nume<<endl;
        cout<<"  Prenume: "<<agenda[i].prenume<<endl;
        cout<<"  Numar de telefon: "<<agenda[i].numar<<endl;
        cout<<"  Adresa de email: "<<agenda[i].email<<endl;
        cout<<"  Varsta: "<<agenda[i].varsta<<endl;
        cout<<"  Adresa: "<<agenda[i].adresa<<endl;
        cout<<endl;
    }
    }
}

void AfisareNumePrenume(){
   if(contor == 1)
    {
        cout<<"Agenda este goala."<<endl<<endl;
        return;
    }
    else
    {
    SetColor(10);
    cout<<endl<<"Contactele existente in agenda sunt:"<<endl<<endl;
    int i;
    for(i=1; i<contor; i++)
        cout<<agenda[i].nume<<" "<<agenda[i].prenume<<endl;}

}


void CautaNume (char *key1)
{
    int found = 0;
    int i;
    char c1 [70];
        for(i=1;i<contor;i++)
        {
            strcpy(c1, agenda[i].nume);
            if(strcmp(c1, key1) == 0)
                {
                    SetColor(10);
                    cout<<endl<<"Contactul cautat este:"<<endl<<endl;
                    cout<<"Nume: "<<agenda[i].nume<<endl;
                    cout<<"Prenume: "<<agenda[i].prenume<<endl;
                    cout<<"Numar de telefon: "<<agenda[i].numar<<endl;
                    cout<<"Adresa de email: "<<agenda[i].email<<endl;
                    cout<<"Varsta: "<<agenda[i].varsta<<endl;
                    cout<<"Adresa: "<<agenda[i].adresa<<endl;
                    found ++;
                }


        }

      if(found==0)
    {
        SetColor(10);
        cout<<"Contactul nu a fost gasit in agenda."<<endl<<endl;
    }
}

void CautaPrenume (char *key1)
{
    int found = 0;
    int i;
    char c1 [70];
        for(i=1;i<contor;i++)
        {
            strcpy(c1, agenda[i].prenume);
            if(strcmp(c1, key1) == 0)
                {
                    SetColor(10);
                    cout<<endl<<"Contactul cautat este:"<<endl<<endl;
                    cout<<"Nume: "<<agenda[i].nume<<endl;
                    cout<<"Prenume: "<<agenda[i].prenume<<endl;
                    cout<<"Numar de telefon: "<<agenda[i].numar<<endl;
                    cout<<"Adresa de email: "<<agenda[i].email<<endl;
                    cout<<"Varsta: "<<agenda[i].varsta<<endl;
                    cout<<"Adresa: "<<agenda[i].adresa<<endl;
                    found ++;
                }


        }

      if(found==0)
    {
        SetColor(10);
        cout<<"Contactul nu a fost gasit in agenda."<<endl<<endl;
    }
}

void CautaTelefon (char *key1)
{
    int found = 0;
    int i;
    char c1 [70];
        for(i=1;i<contor;i++)
        {
            strcpy(c1, agenda[i].numar);
            if(strcmp(c1, key1) == 0)
                {
                    SetColor(10);
                    cout<<endl<<"Contactul cautat este:"<<endl<<endl;
                    cout<<"Nume: "<<agenda[i].nume<<endl;
                    cout<<"Prenume: "<<agenda[i].prenume<<endl;
                    cout<<"Numar de telefon: "<<agenda[i].numar<<endl;
                    cout<<"Adresa de email: "<<agenda[i].email<<endl;
                    cout<<"Varsta: "<<agenda[i].varsta<<endl;
                    cout<<"Adresa: "<<agenda[i].adresa<<endl;
                    found ++;
                }


        }

      if(found==0)
    {
        SetColor(10);
        cout<<"Contactul nu a fost gasit in agenda."<<endl<<endl;
    }
}

bool isPrefix(string str, string corner)
{
    int n = str.length();
    int c2 = corner.length();
    if (n < c2)
       return false;

    return (str.substr(0, c2).compare(corner) == 0);
}

void CautaPrefix (char *key1)
{
    int found = 0;
    int i;
    char c1 [70];



        for(i=1;i<contor;i++)
        {
            strcpy(c1, agenda[i].numar);

               if(isPrefix(c1, key1))
                {
                    SetColor(10);
                    cout<<endl<<"Contactul cautat este:"<<endl<<endl;
                    cout<<"Nume: "<<agenda[i].nume<<endl;
                    cout<<"Prenume: "<<agenda[i].prenume<<endl;
                    cout<<"Numar de telefon: "<<agenda[i].numar<<endl;
                    cout<<"Adresa de email: "<<agenda[i].email<<endl;
                    cout<<"Varsta: "<<agenda[i].varsta<<endl;
                    cout<<"Adresa: "<<agenda[i].adresa<<endl;
                    found ++;
                }


        }

      if(found==0)
    {
        SetColor(10);
        cout<<"Contactul nu a fost gasit in agenda."<<endl<<endl;
    }
}

void Cauta()
{
    SetColor(10);
    cout<<endl<<"In ce mod doriti sa fie realizata cautarea? "<<endl<<endl;
                    cout<<"Pentru a cauta dupa nume apasati tasta 1."<<endl;
                    cout<<"Pentru a cauta dupa prenume apasati tasta 2."<<endl;
                    cout<<"Pentru a cauta dupa numarul de telefon apasati tasta 3."<<endl;
                    cout<<"Pentru a cauta dupa un prefix apasati tasta 4."<<endl<<endl;
                    SetColor(11);
                    cout<<"Optiunea dumneavoastra este: ";

    int optiune;
    SetColor(13);
    cin.ignore();
    cin>>optiune;
    if(optiune==1){
        char key1[30];
            SetColor(11);
            cout<<endl<<"Introduceti numele dorit: ";
            SetColor(13);
            cin.ignore();
            cin.get(key1, 30);
            SetColor(15);
            CautaNume(key1);
    }
    else if(optiune==2){
        char key1[30];
            SetColor(11);
            cout<<endl<<"Introduceti prenumele dorit: ";
            SetColor(13);
            cin.ignore();
            cin.get(key1, 30);
            SetColor(15);
            CautaPrenume(key1);
    }
    else if(optiune==3){
        char key1[30];
            SetColor(11);
            cout<<endl<<"Introduceti numarul de telefon dorit: ";
            SetColor(13);
            cin.ignore();
            cin.get(key1, 30);
            SetColor(15);
            CautaTelefon(key1);
    }
    else if(optiune==4){
        char key1[30];
            SetColor(11);
            cout<<endl<<"Introduceti prefixul dorit: ";
            SetColor(13);
            cin.ignore();
            cin.get(key1, 30);
            SetColor(15);
            CautaPrefix(key1);
    }

}
void Eliminare(char *nume, char *prenume)
{

   if(contor == 1)
    {
        cout<<"Agenda este goala."<<endl;
        return;
    }


    int i, j,q=0;
    for(i=1; i<contor; i++)
    {
        if(strcmp(agenda[i].nume, nume) == 0)
        if(strcmp(agenda[i].prenume, prenume) == 0)
        {

            for(j=i; j<=contor-1; j++)
            {
                agenda[j] = agenda[j+1];
            }
            contor -= 1;
            SetColor(10);
            cout<<endl<<"Contactul a fost eliminat cu succes."<<endl<<endl;
            SetColor (15);
            q++;


        }

    }

    if (q==0)
        {
            SetColor(10);
            cout<<endl<<"Contactul nu a fost gasit in agenda."<<endl<<endl;
            SetColor (15);
        }

    return ;
    }


void Editare (char* nume, char* prenume)
{
    int i,m=0;
    char c1 [30];
    char c2 [30];
        for(i=1;i<contor;i++)
        {
            strcpy(c1, agenda[i].nume);
            strcpy(c2, agenda[i].prenume);

            if(strcmp(c1, nume) == 0)
                if(strcmp(c2, prenume) == 0)
                {
                    m++;
                    int informatie;
                    char change [100];
                    SetColor(11);
                    cout<<endl<<"Care este informatia pe care doriti sa o modificati? "<<endl<<endl;
                    cout<<"Pentru a modifica numele apasati tasta 1."<<endl;
                    cout<<"Pentru a modifica prenumele apasati tasta 2."<<endl;
                    cout<<"Pentru a modifica numarul de telefon apasati tasta 3."<<endl;
                    cout<<"Pentru a modifica adresa de email apasati tasta 4."<<endl;
                    cout<<"Pentru a modifica varsta apasati tasta 5."<<endl;
                    cout<<"Pentru a modifica adresa apasati tasta 6."<<endl;
                    cout<<"Pentru a reveni la meniul initial apasati tasta 7."<<endl<<endl;
                    cout<<"Optiunea dumneavoastra este: ";

                    SetColor(13);
                    cin.ignore();
                    cin>>informatie;
                    if (informatie==1)
                        {
                        strcpy(agenda[i].nume, " ");
                        SetColor(11);
                        cout<<"Scrieti noul nume mai jos: "<<endl;
                        cout<<"Nume: ";
                        SetColor(13);
                        cin.ignore();
                        cin.get(change,100);
                        strcpy(agenda[i].nume, change);
                        SetColor(10);
                        cout<<"Contactul a fost editat cu succes."<<endl;
                        return;
                        }
                    else if (informatie==1)
                        {
                        strcpy(agenda[i].prenume, " ");
                        SetColor(11);
                        cout<<"Scrieti noul prenume mai jos: "<<endl;
                        cout<<"Prenume: ";
                        SetColor(13);
                        cin.ignore();
                        cin.get(change,100);
                        strcpy(agenda[i].prenume, change);
                        SetColor(10);
                        cout<<"Contactul a fost editat cu succes."<<endl;
                        return;
                        }
                    else if (informatie==3)
                        {
                        strcpy(agenda[i].numar, " ");
                        SetColor(11);
                        cout<<"Scrieti noul numar de telefon mai jos: "<<endl;
                        cout<<"Numar de telefon: ";
                        SetColor(13);
                        cin.ignore();
                        cin.get(change,100);
                        strcpy(agenda[i].numar, change);
                        SetColor(10);
                        cout<<"Contactul a fost editat cu succes."<<endl;
                        return;
                        }
                    else if (informatie==4)
                        {
                        strcpy(agenda[i].email, " ");
                        SetColor(11);
                        cout<<"Scrieti noua adresa de email mai jos: "<<endl;
                        cout<<"Adresa de email: ";
                        SetColor(13);
                        cin.ignore();
                        cin.get(change,100);
                        strcpy(agenda[i].email, change);
                        SetColor(10);
                        cout<<"Contactul a fost editat cu succes."<<endl;
                        return;
                        }
                    else if (informatie==5)
                        {
                        strcpy(agenda[i].varsta, " ");
                        SetColor(11);
                        cout<<"Scrieti noua varsta mai jos: "<<endl;
                        cout<<"Varsta: ";
                        SetColor(13);
                        cin.ignore();
                        cin.get(change,100);
                        strcpy(agenda[i].varsta, change);
                        SetColor(10);
                        cout<<"Contactul a fost editat cu succes."<<endl;
                        return;
                        }
                    else if (informatie==6)
                        {
                        strcpy(agenda[i].adresa, " ");
                        SetColor(11);
                        cout<<"Scrieti noua adresa mai jos: "<<endl;
                        cout<<"Adresa: ";
                        SetColor(13);
                        cin.ignore();
                        cin.get(change,100);
                        strcpy(agenda[i].adresa, change);
                        SetColor(10);
                        cout<<"Contactul a fost editat cu succes."<<endl;
                        return;
                        }

                    else if (informatie==7)
                        {
                        return;
                        }

            if(informatie!=6)
            SetColor(10);
            cout<<endl<<"Contactul a fost modificat cu succes."<<endl<<endl;


                }


}
         if(m==0)
        {
            SetColor(10);
            cout<<endl<<"Contactul nu a fost gasit in agenda."<<endl<<endl;
            SetColor (15);
        }
}

void Optiune ()
{
    int optiune;
    SetColor (11);
    cout<<"Va rugam sa alegeti o optiune (scrieti cifra corespunzatoare acesteia)."<<endl;
    cout<<"Optiunea aleasa de dumneavoastra este:";
    SetColor(13);
    cin>>optiune;
    cout<<endl;
    SetColor (15);
    if(optiune==1)
    {

            SetColor(15);
            AfisareContacte();
    }
    else if(optiune==2)
    {

            SetColor(15);
            AfisareNumePrenume();
    }
    else if(optiune==3)
    {
            SetColor(15);
            Cauta();

    }
    else if(optiune==4)
    {
            SetColor(11);
            cout<<endl<<"Introduceti datele noului contact:"<<endl<<endl;;
            SetColor(15);
            Adauga();
    }

    else if(optiune==5)
    {

            char key1[30];
            char key2[30];
            SetColor(11);
            cout<<endl<<"Introduceti numele persoanei al carui contact doriti sa il eliminati : ";
            SetColor(13);
            cin.ignore();
            cin.get(key1,30);
            SetColor(15);
            SetColor(11);
            cout<<"Introduceti prenumele persoanei al carui contact doriti sa il eliminati : ";
            SetColor(13);
            cin.ignore();
            cin.get(key2,30);
            SetColor(15);
            Eliminare(key1, key2);
            SetColor(15);
    }

    else if(optiune==6)
    {

            char nume[30];
            char prenume[30];
            SetColor(11);
            cout<<endl<<"Introduceti numele persoanei al carui contact doriti sa il modificati : ";
            SetColor(13);
            cin.ignore();
            cin.get(nume,30);
            SetColor(11);
            cout<<"Introduceti prenumele persoanei al carui contact doriti sa il modificati : ";
            SetColor(13);
            cin.ignore();
            cin.get(prenume,30);
            SetColor(15);
            Editare(nume,prenume);
            SetColor(15);

    }

    else if(optiune==7)    {

            SetColor(10);
            cout<<"Numarul de contacte din agenda dumneavoastra este egal cu: "<<contor-1<<endl;
    }

    else if(optiune==8)    {exit( 0 );}



        saveToFile();
        SetColor(15);

}

int main()
{

    readFromFile();
    SetColor (15);
    cout<<"Iulia Gheorghe"<<endl<<endl<<endl;;

    TextAgenda();
    TextTelefonica();
    SetColor(11);
    cout<<endl<<"Bine ati venit!"<<endl;
    cout<<"Va rugam sa introduceti parola:";
    Parola();
    TextMeniu();
    Optiune();
    int optiune;
    SetColor(11);
    cout<<endl<<"Doriti sa continuati?"<<endl<<endl;
    cout<<"Pentru DA apasati tasta 1."<<endl;
    cout<<"Pentru NU apasati tasta 0."<<endl;
    cout<<"Pentru a va reaminti meniul apasati tasta 2."<<endl<<endl;
    cout<<"Optiunea dumneavoastra este: ";
    SetColor (13);
    cin>>optiune;
    cout<<endl;
    int p=-1;
    while(p<0)
    {
    if(optiune==1)
    {
    Optiune();
    SetColor(11);
    cout<<endl<<"Doriti sa continuati?"<<endl<<endl;
    cout<<"Pentru DA apasati tasta 1."<<endl;
    cout<<"Pentru NU apasati tasta 0."<<endl;
    cout<<"Pentru a va reaminti meniul apasati tasta 2."<<endl<<endl;
    cout<<"Optiunea dumneavoastra este: ";
    SetColor(13);
    cin>>optiune;
    cout<<endl;
    }
    else if (optiune==2)
    {
    TextMeniu();
    Optiune();
    SetColor(11);
    cout<<endl<<"Doriti sa continuati?"<<endl<<endl;
    cout<<"Pentru DA apasati tasta 1."<<endl;
    cout<<"Pentru NU apasati tasta 0."<<endl;
    cout<<"Pentru a va reaminti meniul apasati tasta 2."<<endl<<endl;
    cout<<"Optiunea dumneavoastra este: ";
    SetColor(13);
    cin>>optiune;
    cout<<endl;
    }
    else if(optiune==0) {exit( 0 );}
    }

    return 0;
}

