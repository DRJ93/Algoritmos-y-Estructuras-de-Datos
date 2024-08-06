#include <iostream>

using namespace std;

int main()
{
/*
Ej. MI-30: Dado un conjunto de valores enteros, calcular e informar a) cuántos valores cero
hubo, b) promedio de valores positivos, c) sumatoria de valores negativos.
Resolver el ejercicio para los siguientes lotes de datos:
1) 167 valores enteros
2) N valores, donde el valor de N debe ser leído previamente
3) El conjunto de valores termina con un valor igual al anterior
4) Se dan N valores, pero el proceso deberá finalizar si se procesan todos los valores o si
la cantidad de ceros supera a cuatro
5) Se dan N valores, pero el proceso deberá finalizar si se cumple alguna de las
condiciones de 4) o si el promedio de positivos resulta mayor que seis.
*/
   int valor, nulo, positivo, negativo, valorAnterior;
   float promedio, contadorPositivos;

   contadorPositivos = 0;
   negativo = 0;
   positivo = 0;
   promedio = 0;
 /*-----1-------*/
   /*  for (int i=1; i<= 7; i++){
    cout<<"Ingrese un valor"<<endl;
    cin>>valor;

    if(valor >0){
        contadorPositivos++;
        promedio = (positivo += valor)/contadorPositivos;
    }
    if(valor <0){
        negativo += valor;
    }
    else if(valor==0) {
        nulo++;
    }

    cout<<"PROMEDIO POSITIVOS: "<< promedio<< " Cantidad de Ceros: "<<nulo<< " Sumatoria de los negativos: "<< negativo<<endl;
    }
    return 0;

}
*/
   /*Para el caso 2:
   int limite
    cout <<"Ingrese un limite"<< endl;
    cin>>limite;
    for (int i=1; i<= limite; i++){
        +
        +
        +
    }
   */

 /*
   Para el caso 3....
   */
   cout<<"Ingrese un valor"<<endl;
    cin>>valor;
   do {


    if(valor >0){
        contadorPositivos++;
        promedio = (positivo += valor)/contadorPositivos;
    }
    if(valor <0){
        negativo += valor;
    }
    else if(valor==0) {
        nulo++;
    }


    valorAnterior = valor;
    cout<<"Ingrese un valor"<<endl;
    cin>>valor;
    }
    while(valor != valorAnterior);
    cout<<"PROMEDIO POSITIVOS: "<< promedio<< " Cantidad de Ceros: "<<nulo<< " Sumatoria de los negativos: "<< negativo<<endl;
   return 0;
   }



