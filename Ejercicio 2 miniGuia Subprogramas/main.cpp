#include <iostream>

using namespace std;
/*
Modifique el programa anterior para convertir el subprograma en un procedimiento (return
void). El valor absoluto debe aplicarse directamente sobre el parámetro actual (pasaje por
referencia).

----Programa anterior----

    Confeccione una función que , dado un valor por parámetro, devuelva el módulo de dicho
    valor a través de su invocación. Que devuelva un valor a través de su invocación quiere decir
    que tiene que tiene que devolver dicho valor a través del return.

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


*/
void valorAbsoluto(int &x){
    if (x<0)
        cout<< "valor absoluto = "<< x * (-1)<< endl;
    else
        cout<< "valor absoluto = "<< x << endl;
    return;
}


int main()
{
    int x;
    cout<<" Ingrese un valor para obtener su valor absoluto"<<endl;
    cin>> x;
    valorAbsoluto(x);

    return 0;
}
