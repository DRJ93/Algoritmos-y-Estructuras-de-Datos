
#include<iostream>
using namespace std;

/*
Dada una terna de n�meros naturales que representan al d�a, al mes y al a�o de una
determinada fecha informarla como un solo n�mero natural de 8 d�gitos con la forma
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

