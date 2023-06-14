#include <iostream>
#include "functii.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <dos.h>
using namespace std;

#define MaxNo_Menu 6

HANDLE con=GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(int x,int y)
{
    COORD Coord;
    Coord.X=x;
    Coord.Y=y;

    SetConsoleCursorPosition(con,Coord);
}

void textattr(int color)
{
    SetConsoleTextAttribute(con, color);
}

const int MAXIM_INCERCARI=6;  ///initializez numarul de incercari
int spanzu::introducereLitera (char nimerire, string secretliteraa, string &nimerireliteraa)
{
    int i;
    int nimeriri=0;
    int len=secretliteraa.length();
    for (i = 0; i< len; i++)
    {

        if (nimerire == nimerireliteraa[i])
            return 0;

        if (nimerire == secretliteraa[i])
        {
            nimerireliteraa[i] = nimerire;
            nimeriri++;
        }
    }
    return nimeriri;
}
int get_code(void)
{
    int ch = getch();

    if (ch == 0 || ch == 224)
        ch = 256 + getch();
    return ch;
}
enum
{
    KEY_ESC = 27,
    ARROW_UP = 256 + 72,
    ARROW_DOWN = 256 + 80,
    ARROW_LEFT = 256 + 75,
    ARROW_RIGHT = 256 + 77
};
char spanzu::meniu()
{
    char op='m';

    // This piece of code hides the cursor !!
    HANDLE hConsoleOutput;
    CONSOLE_CURSOR_INFO structCursorInfo;
    hConsoleOutput = GetStdHandle( STD_OUTPUT_HANDLE );
    GetConsoleCursorInfo( hConsoleOutput, &structCursorInfo );
    structCursorInfo.bVisible = false;
    SetConsoleCursorInfo( hConsoleOutput, &structCursorInfo );


    string menu_list[MaxNo_Menu] = { "Joc Nou", "Instructiuni", "Dificultate", "Manual de utilizare", "Informatii autor", "Iesire" };
    int i,xpos = 1,ypos[MaxNo_Menu] = { 3, 6, 9, 12, 15, 18 };

    // afisez meniul
    for (i=0; i< MaxNo_Menu; ++i)
    {
        gotoxy(xpos, ypos[i] );
        textattr(10);
        cout<<menu_list[i];
    }

    for(int i=1; i<20; i++)    //// verticala
    {
        gotoxy(21,i);
        textattr(1000);
        cout<<"||\n";

    }
    for(int i=0; i<21; i++)   ////orizontala de sus
    {
        gotoxy(i,20);
        cout<<"<+>\n";
        textattr(1000);
    }
    for(int i=0; i<21; i++)   ///orizontala de jos
    {
        gotoxy(i,0);
        cout<<"<+>\n";
        textattr(1000);

    }
    textattr(44);
    gotoxy(35,1);


    /// aleg optiuni din meniu
    i=0;
    while(1)
    {
        gotoxy(xpos, ypos[i]);
        textattr(225);
        cout<<menu_list[i] ;

        /* note : 72 -> UP button
        	75 -> RIGHT button
            77 -> LEFT button
            80 -> DOWN button
        */
        int action;
        switch(action = get_code())
        {
        case ARROW_UP:
            if(i>0)
            {
                gotoxy(xpos,ypos[i] );
                textattr(14);
                cout<<menu_list[i] ;
                --i;
            }
            break;

        case ARROW_DOWN:
            if(i< MaxNo_Menu-1 )
            {
                gotoxy(xpos,ypos[i] );
                textattr(14);
                cout<<menu_list[i] ;
                ++i;
            }
            break;

        case 13:
            if(i==0)
            {
                gotoxy (20,7);
                fflush(stdin);
                op='A';
                textattr(14);
            }
            if(i==1)
            {
                gotoxy (20,7);
                fflush(stdin);
                op='I';
                textattr(14);
            }
            if(i==2)
            {
                gotoxy (20,7);
                fflush(stdin);
                op='D';
                textattr(14);
            }
            if(i==3)
            {
                gotoxy (20,7);
                fflush(stdin);
                op='M';
                textattr(14);
            }
            if(i==4)
            {
                gotoxy (20,7);
                fflush(stdin);
                op='T';
                textattr(14);

            }
            if(i==5)
            {
                gotoxy (20,7);
                fflush(stdin);
                op='X';
                gotoxy(20,21);
                textattr(15);
                exit(0);

            }
            break;
        }
        if (op != 'm')
        {
            system("cls");
            return op;
        }
    }
    return 0;
}

char spanzu::meniu2()
{
    char op2;
    cout<<"\n\n\n\t\t Sunteti sigur ca doriti sa parasiti jocul?:";
    cout<<"\n\t\t\t D-Da";
    cout<<"\n\t\t\t N-Nu"<<endl<<"\t->";
    op2=toupper(getche () );
    return op2;
}
void spanzu::spanzuratoarea( int dificultate ) /// transmit prin parametru dificultatea jocului

{
    //char op;
    string name;
    char litera;
    int nr_incercari_nereusite=0;
    string literaa;
    char gresit[ 255 ];    /// memorez literele introduse de la tastatura
    int liber = 0;

    string cuvinte_usor[] =
    {
        "mare",
        "universitate",
        "abracadabra",
        "televiziune",
        "oxigen",
        "abecedar",
        "alfabet",
        "inteligenta",
        "electromagnetic",
        "fluorescent",
        "telecomanda",
        "navigatie",
        "electromotor",
        "leopard",
        "management",
        "economie",
        "responsabilitate",
    };

    string cuvinte_mediu[] =
    {
        "abracadabra",
        "televiziune",
        "oxigen",
        "abecedar",
        "temperament",
        "alfabet",
        "inteligenta",
        "electromagnetic",
        "fluorescent",
        "telecomanda",
        "navigatie",
        "electromotor",
        "leopard",
        "decodor",
        "management",
        "economie",
        "responsabilitate",
        "didactic",
        "temperatura",
    };

    string cuvinte_greu[] =
    {
        "sternocleidomastoidian",
        "dezoxiribonucleic",
        "electroglotospectrografie",
        "teleenciclopedie",
        "neinteligibil",
        "schizofrenie",
        "ortopantomografie",
        "lichefiabile",
        "zbenghi",
        "picnomorf",
        "valvulotomie",
        "izdat",
        "turgid",
    };

    srand(time(NULL));
    int n=rand () % 10;
    if( dificultate == 1 )
        literaa=cuvinte_usor[n];
    else if( dificultate == 2 )
        literaa = cuvinte_mediu[ n ];
    else if( dificultate == 3 )
        literaa = cuvinte_greu[ n ];
    string unknown(literaa.length(),'-');
    cout << "\n\n\t\t\t\t SPANZURATOAREA\n";
    cout << "********************************************************************************";
    cout << "\nAi " << MAXIM_INCERCARI << " Incercari sa ghicesti cuvantul.";

    while (nr_incercari_nereusite < MAXIM_INCERCARI)
    {
        cout << "\n\n\t   LITERE INCERCATE, GRESITE: ";

        for( int i=0; i<liber; i++ )
            cout << gresit[ i ] << " ";
        cout << "\n\n" << unknown;
        cout << "\nGhiceste litera ";
        cin >> litera;

        if (introducereLitera(litera, literaa, unknown)==0)
        {
            nr_incercari_nereusite++;
            if (nr_incercari_nereusite==1)
            {
                gresit[ liber ] = litera;
                liber ++;

                cout<<"\n litere gresite:"<<litera;
                cout<<endl;
                cout<<"           ";
                cout<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        ";
                cout<<(char)221;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"      o o o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o * * o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o  |  o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"      o o o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        |"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"         "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"         "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"         "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"          "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<endl;
                cout << endl << "NU AI NIMERIT!" << endl;
            }
            if(nr_incercari_nereusite==2)
            {
                gresit[ liber ] = litera;
                liber ++;

                system("cls");
                cout<<"\n litere gresite:"<<litera<<endl;
                cout<<"           ";
                cout<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        ";
                cout<<(char)221;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"      o o o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o * * o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o  |  o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"      o o o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        |"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o  "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"         "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<endl;
                cout << endl << "NU AI NIMERIT!" << endl;
            }

            if(nr_incercari_nereusite==3)
            {
                gresit[ liber ] = litera;
                liber ++;

                system("cls");
                cout<<"           ";
                cout<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        ";
                cout<<(char)221;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"      o o o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o * * o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o  |  o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"      o o o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        |"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     oooo"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o  o  "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"          "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<endl;
                cout << endl << "NU AI NIMERIT!" << endl;
            }
            if(nr_incercari_nereusite==4)
            {
                gresit[ liber ] = litera;
                liber ++;

                system("cls");
                cout<<"           ";
                cout<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        ";
                cout<<(char)221;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"      o o o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o * * o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o  |  o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"      o o o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        |"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     ooooooo"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o  o  o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"         "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"          "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<endl;
                cout << endl << "NU AI NIMERIT!" << endl;
            }
            if(nr_incercari_nereusite==5)
            {
                gresit[ liber ] = litera;
                liber ++;

                system("cls");
                cout<<"           ";
                cout<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        ";
                cout<<(char)221;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"      o o o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o * * o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o  |  o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"      o o o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        |"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     ooooooo"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o  o  o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"      o   "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o     "<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<endl;
                cout << endl << "NU AI NIMERIT!" << endl;
            }
            if(nr_incercari_nereusite==MAXIM_INCERCARI)
            {
                gresit[ liber ] = litera;
                liber ++;

                system("cls");
                cout<<"           ";
                cout<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<(char)220<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        ";
                cout<<(char)221;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"      o o o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o x x o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o  |  o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"      o o o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        |"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     ooooooo"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o  o  o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"        o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"      o   o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<"     o     o"<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<endl;
                cout<<"           ";
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<(char)219;
                cout<<endl;
                cout << endl << "NU AI GHICIT!" << endl;
            }
        }
        else
        {
            system("cls");
            cout << endl << "FELICITARI!!!!AI GHICIT" << endl;
        }
        cout << "MAI AI " << MAXIM_INCERCARI - nr_incercari_nereusite;
        cout << " INCERCARI RAMASE." << endl;
        if (literaa==unknown)
        {
            cout << "AI REUSIT!"<<endl;
            cout <<"Cuvantul era: "<< literaa << endl;
            break;
        }
    }
    if(nr_incercari_nereusite == MAXIM_INCERCARI)
    {
        cout << "\nAI FOST SPANZURAT." << endl;
        cout << "Cuvantul era: " << literaa << endl;
    }
    cin.ignore();
    cin.get();
    system("cls");
    meniu();
}
void derivata::joc()
{
    int executaOptiuneAlegeDificultate = 0;
    int corect = 1;
    do
    {
        int dificultate;
        char buff[ 3 ];
        system("cls");
        switch( meniu() )
        {
        case 'A':
            if( executaOptiuneAlegeDificultate == 1 )
                spanzuratoarea( dificultate );
            else
            {
                cout << "\n\t\tAlegeti mai intai un nivel de dificultate!";
            }
            break;
        case 'I':
            cout<<"\n\t\t\t\t INSTRUCTIUNI\n\n Trebuie sa ghicesti un cuvant sau mai multe prin incercari succesive de litere. In mod clasic se juca"
                "  pe o foaie de hartie impotriva unui prieten, dar aici   poti juca impotriva calculatorului, folosind dictionare din mai multe categorii."
                "  Dupa fiecare incercare, litera selectata se inlocuieste automat in interiorul   cuvantului, sau in caz de esec se completeza"
                "  desenul. Daca gresesti de mai   mult de 6 ori, calculatorul te spanzura :). Succes ! "<<endl;
            break;
        case 'D':
            cout<<endl;
            cout<<"\n\talegeti dificultatea: " << endl;
            cout <<"\t\t\t[ 1 ]-> usor\n\t\t\t[ 2 ]-> mediu\n\t\t\t[ 3 ]-> greu\n\t\t\t\t\t-->";
            fflush( stdin );
            cin.getline( buff, 3, '\n' );
            if( atoi( buff ) == 1 )
                dificultate = 1;
            else
            {
                if( atoi( buff ) == 2 )//asci to integer - din caracter in intreg
                    dificultate = 2;
                else
                {
                    if( atoi( buff ) == 3 )
                        dificultate = 3;
                    else
                    {
                        cout << "\n\t\tOPTIUNEA INTRODUSA NU EXISTA! Se revine la meniu!";
                        corect = 0;
                    }
                }
            }
            if( corect == 1 )
                executaOptiuneAlegeDificultate = 1;
            break;
        case 'M':
            cout<<"\n\t\t\tMANUAL DE UTILIZARE "
                "\n  Pentru a incepe un joc nou, selectati Joc Nou. In momentul cand selectati Joc Nou, va aparea un mesaj:"
                " 'Alegeti mai intai un nivel de dificultate'.  Pentru a face acest lucru selectati Dificultate ,  unde aveti posibilitatea"
                "de a alege un nivel de   dificultate din cele trei posibilitati.\nDupa ce ati ales dificultatea,incepeti un Joc Nou."
                "Deasemenea aveti posibilitateade a citi instructiunile jocului.\n Pentru a vedea date despre autorul acestui joc selectati Informatii Autor.\nIn momentul in care doriti sa iesiti din joc selectati Iesire,   unde tot odata aveti posibilitatea sa va razganditi."<<endl;
            break;
        case 'T':
            cout<<"\n\t\tProgramul a fost realizat de:\n\t\t\t\tstudent:      Hreceniuc Larisa"
                "\n\t\t\t\tan studiu:    II"
                "\n\t\t\t\tspecializare: Calculatoare"
                "\n\t\t\t\tgrupa:        3121 A"<<endl;
            break;
        case 'X':
            bool boolD; //variabila de tip booleana- adevarat sau fals
            boolD=true;
            while(boolD)
            {
                switch(meniu2())
                {
                case 'D':
                    exit(0);
                case 'N':
                    system("cls");
                    cout<<"\n Continuati sa jucati";
                    boolD=false;
                }
            }
            break;
        default:
            cout<<"\n\nAlegere incorecta";
            cout<<"\nApasati enter pentru a continua";
            getchar();
            system("cls");
            meniu();
        }
        getch();
    }
    while(1);
}
