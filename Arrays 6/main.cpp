#include <iostream>
#include <conio.h>
using namespace std;
/*
6. Realice un subprograma que muestre el contenido de un vector en forma
ordenada descendentemente. El tamaño del array es informado por
parámetro

*/
/*BUBBLE SORT MEJORADO :D*/
void ordenarDescendentemente(int v[], int tam){
    int aux;
   for(int i = 0; i < tam - 1; i++) {
        for(int j = 0; j < tam - 1 - i; j++) {
            if(v[j] > v[j + 1]) { // Orden descendente, el <, >, del if cambia el sentido del ordenamiento
                aux = v[j + 1];
                v[j + 1] = v[j];
                v[j] = aux;
            }

        }
    }
   return;
}
int main(){
    int vec[5] = {85,12,29,35,26};

       for(int i = 0; i<5; i++){
        cout << "El vector desordenado es: v[" << i<< "] = "<< vec[i]<< endl;
    }
    ordenarDescendentemente(vec, 5);
  for(int i = 0; i < 5; i++) {
    printf("El vector ordenado es: v[%d] = %d\n", i, vec[i]);
}
    return 0;
}




