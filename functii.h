#ifndef FUNCTII_H
#define FUNCTII_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include<conio.h>
using namespace std;
//const int MAXIM_INCERCARI=6;
class spanzu
{
public:
    int introducereLitera (char,string,string &);
    char meniu();
    char meniu2();
    void spanzuratoarea( int dificultate );
};
class derivata : public spanzu
{
public:
    void joc();
};

#endif // FUNCTII_H
