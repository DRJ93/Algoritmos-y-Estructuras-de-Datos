#include <iostream>

using namespace std;

int main()
{
    int valor, mayor;
    //Ej. MI-20: Dados 10 valores informar el mayor
     for( int i=1; i<= 10; i++ ){
        cout<<"Ingrese un valor"<<endl;
        cin>> valor;
        if(valor >= mayor || mayor == 0 ){
            mayor = valor;
        }

     }
    cout<< "el mayor de los 10 valores es "<< mayor << endl;
    return 0;
}
