#include <iostream>

using namespace std;

/*
 Elabore un procedimiento que reciba tres par�metros, n1, n2 y mayor. A trav�s del
par�metro �mayor� devuelva el mayor n�mero entre n1 y n2.
*/

void comparacion(int n1, int n2, int &mayor)
{
    if (n1>n2)
        mayor = n1;
    if(n2>n1)
        mayor = n2;
    return;
}
int main()
{   int n1, n2;
    int mayor = 0;
    cout << "Ingrese valores a comparar" << endl;
    cin>> n1>> n2;
    comparacion(n1, n2, mayor);
    cout<<"El numero mayor es: "<< mayor<<endl;

    return 0;
}
