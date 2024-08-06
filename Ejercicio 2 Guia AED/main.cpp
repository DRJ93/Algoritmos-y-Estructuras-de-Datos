
#include<iostream>
using namespace std;

/*
Dada una terna de números naturales que representan al día, al mes y al año de una
determinada fecha informarla como un solo número natural de 8 dígitos con la forma
(AAAAMMDD).
*/
int main()
{
    int a, m, d;

    cout<< "Ingrese el anio de su fecha:"<<endl;
    cin>>a;

    cout<< "Ingrese el mes de su fecha"<< endl;
    cin>> m;

    cout<<"Ingrese el dia de su fecha"<<endl;
    cin>> d;

    cout<< a*(10*10*10*10) + m *(10*10) + d << endl;




    return 0;
}

