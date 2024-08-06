#include <iostream>

using namespace std;
 /*
 : A partir de un valor entero ingresado por teclado, se pide informar:
a) La quinta parte de dicho valor
b) El resto de la divisi�n por 5
c) La s�ptima parte del resultado del punto a)
 */
int main()
{
   int valorIngresado, a;

   cout<<"Ingrese un valor entero"<<endl;
   cin>> valorIngresado;

    a = valorIngresado/5;

    cout<< a << " Es la quinta parte del valor ingresado."<< endl;
    cout<<valorIngresado%5<<" Este es el resto de la division"<< endl;
    cout<<a/7<< " Es la septima parte de la division"<<endl;
   return 0;

}
