#include <iostream>
#include <conio.h>

using namespace std;
/*
Diseñar un algoritmo recursivo, que permita invertir el contenido de un
vector. Como indica el ejemplo:
Vector original: 28 35 12 43 56 77
Vector invertido: 77 56 43 12 35 28
El algoritmo no podrá usar un vector auxiliar
*/
/*Solucion no recursiva*/
void invertir (int v[], int tam){
    int aux, auxF;
    for(int i = 0; i<tam; i++){
        aux = v[i];
        auxF = v[tam-i];
        v[tam-i] = aux;
        v[i] = auxF;
    }
}
/*solucion recursiva*/
/*
void invert(int vec[], int i, int tam)
{
    int aux;
    if (i < tam/2)
    {
        aux = vec[i];
        vec[i] = vec[tam-1-i];
        vec[tam -1- i] = aux;
        invert(vec, i+1, tam);
    }
    return;

}

*/
int main()
{
   int  v[] = {1,2,3,4,5,6,7,8,9};
   for(int i = 0; i<9; i++){
        cout << "El vector en la posicion ["<<i<<"] es = "<< v[i]<<endl;
   }
    invertir(v, 8);
    cout<<"El vector al revés: " << endl;
       for(int i = 0; i<9; i++){
        cout << "El vector en la posicion ["<<i<<"] es = "<< v[i]<<endl;
   }
    return 0;
}
/*Recordatorio*/
/* A la hora de trabajar con subprogramas que edite arrays, y sea eso lo que interesa sacar de ahi, es mejor el uso de procedimientos.
