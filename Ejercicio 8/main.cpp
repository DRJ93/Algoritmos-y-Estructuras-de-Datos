#include <iostream>

using namespace std;

int main()
{
/*
    Dado un tri�ngulo representado por sus lados L1, L2, L3, determinar e imprimir
    una leyenda seg�n sea: equil�tero, is�sceles o esc�lenos.
*/
int l1, l2, l3;
    cout<< "Ingrese los lados del triangulo"<<endl;
    cin>> l1>>l2>>l3;

    if(l1==l2 && l2==l3)
        {
            cout<< "Es equilatero"<<endl;
        }
        else {
                if(l1==l2|| l1==l3|| l3==l2)
                    {
                        cout<< "es isoseles"<<endl;
                    }
                else
                    {
                        cout<< "Es escaleno"<<endl;
                    }
        }

    return 0;
}
