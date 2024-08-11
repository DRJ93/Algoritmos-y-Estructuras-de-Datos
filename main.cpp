#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
/*---------------------ENUNCIADO---------------------------*/
/*
Desarrollar una función que calcule el máximo común divisor de dos números
enteros A, B con el siguiente algoritmo:
    1) Dividir A por B, y calcular el resto (0 < R < B)
    2) Si R = 0, el MCD es B, si no seguir en 3)
    3) Reemplazar A por B, B por R, y volver al paso 1)
*/
int CalcularMcd(int &a, int &b )
{
    int r;
    //Como necesito que,  por lo menos, se ejecute una vez, utilizo un do while.
        do{
                //verifico que sean distinto de 0, para poder realizar la division.
            if(b!=0 && a!=0)
                {
                    r = a%b;
                    //Si el resto el 0, el valor del MCD, es b.
                    if(r==0){
                        return b;
                }
                //Si no, reemplazo a por b, y b por r
                else
                    {
                        a = b;
                        b = r;
                    }
                }
           //En caso de B = 0, pido que se reingresen los valores.
            else{
                cout<<"ingrese valores validos"<<endl;
                cin>> a >>b;
            };
        }while(0<r<=b);
        return r;
};

int main()
{   //Declaro variables
    int x,y, mcd;
    //  Ingreso Valores
    cout << "Ingrese los valores para calcular su Maximo Comun Divisor" << endl;
    cin>> x>> y;
    //Invoco la funcion
    mcd = CalcularMcd(x, y);
    //Muestro por pantalla
    cout<< "mcd = "<<mcd<<endl;
    return 0;
}
