#include <iostream>

using namespace std;
/*
Modifique el programa anterior para convertir el subprograma en un procedimiento (return
void). El valor absoluto debe aplicarse directamente sobre el par�metro actual (pasaje por
referencia).

----Programa anterior----

    Confeccione una funci�n que , dado un valor por par�metro, devuelva el m�dulo de dicho
    valor a trav�s de su invocaci�n. Que devuelva un valor a trav�s de su invocaci�n quiere decir
    que tiene que tiene que devolver dicho valor a trav�s del return.

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
