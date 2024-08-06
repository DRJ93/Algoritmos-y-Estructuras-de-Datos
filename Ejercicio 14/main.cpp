#include <iostream>

using namespace std;
//: Dados 50 números enteros, informar el promedio de los mayores que 100 y la
//suma de los menores que –10.

int main()
{
    int valor, mayores, menores, contador, promedio, suma;
    menores= 0;
    mayores=0;
    contador= 0;
    for (int i=1; i<= 10; i++ ){

        cout<<"Ingrese un valor"<<endl;
        cin>> valor;
        if(valor > 100){
           mayores += valor;
        //   cout<<mayores<<endl;
        //   cout<<i<<endl;
        contador++;
        promedio = mayores/ contador;
           cout<< "eL PROMEDIO DE LOS MAYORES DE 100 ES "<<promedio<<endl;

        } else if(valor < -10){
        //        cout<< valor<<endl;
        //        cout<< menores<<endl;
        suma= menores += valor;
                cout<< "La suma de los menores a -10 es "<< suma<< endl;
        }
        else{
            cout<<"El valor ingresado no esta en el rango a analizar"<<endl;
        }

        cout<<"Promedio de los mayores a 100: "<< promedio<<" .Suma de los menores a -10: "<< suma<< endl;

    }
    return 0;
}
