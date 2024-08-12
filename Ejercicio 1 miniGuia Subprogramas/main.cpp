#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

/*
    Confeccione una función que , dado un valor por parámetro, devuelva el módulo de dicho
    valor a través de su invocación. Que devuelva un valor a través de su invocación quiere decir
    que tiene que tiene que devolver dicho valor a través del return.
*/
int modulo(int x)
{
    if(x<0)
        return x * (-1);
    else
        return x;
}

int main()
{
    int x;
    cout << "Ingrese el numero que quiera, pra calcular su valor absoluto" << endl;
    cin>> x;
    cout<< "El valor absoluto de "<< x<<" es "<<modulo(x)<<endl;
    return 0;
}
