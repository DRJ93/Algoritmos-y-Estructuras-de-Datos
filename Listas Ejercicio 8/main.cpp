#include <iostream>
#include <conio.h>
using namespace std;
/*
8. Utilizando una pila y una cola, confeccione un programa que verifique si un número
ingresado por el usuario es capicúa.
Aclaración: conviene que se ingrese cada dígito como caracteres y se vayan tomando
de a uno mientras se encola y se apila el carácter. Luego se van quitando los elementos
de las estructuras en cuestión y comparando

*/
struct NodoPila{
    char info;
    NodoPila *sgte = NULL;
};
struct NodoCola{
    char info;
    NodoCola *sgte = NULL;
};
void queue(NodoCola *&cola, char n ){
    NodoCola *aux = cola;
    cola = new NodoCola();
    cola->info = n;
    if(cola){
        cola->sgte = aux;
    }
    return;
}
char dequeue(NodoCola *&cola){
    NodoCola *ant = NULL;
    NodoCola *aux = cola;
    if (!cola) {  // Verifica si la cola está vacía
        cout << "COLA VACIA" << endl;
        return 'f';  // Indicador de error, en este caso 'f'
    }
    while(aux->sgte){ //se "persiguen" hasta que aux == NULL y ant == ultimo Nodo
        ant = aux;
        aux = aux->sgte;
    }
    char n = aux->info; //Guardo la info del ultimo nodo.
    if(ant) { //ant es False si no entra al while, o sea, el nodo es unico o esta vacia.
            ant -> sgte = NULL;
        }
    else  {
            cola = NULL;
        }
    delete aux;
    return n;
}
void push(NodoPila *&pila, char n){
    NodoPila *aux = pila;
    pila = new NodoPila();
    pila->info = n;
    if(pila){
        pila->sgte = aux;
    }


    return;
}
char pop(NodoPila *&pila){

    if(!pila){
     cout<<"PILA VACIA"<<endl;
            return'f';
        }
        NodoPila *aux;
        char n = pila->info;
        aux = pila;
        pila = pila->sgte;//Si el nodo es unico pila->sgte = NULL
        delete aux;

    return n;
}

int main()
{
    NodoPila *pila = NULL;
    NodoCola *cola = NULL;
    char n;
    for(int i = 0; i<4; i++){
        cout<<"ingrese el "<<i+1<<" digito de su numero"<<endl;
            cin>> n;
            push(pila, n);
            queue(cola, n);
        }
    int c = 0;
    for(int i = 0; i<4; i++){
         cout<<"=== Comparando valores... === "<<endl;

         if(pop(pila)==dequeue(cola)){
            cout<<"El valor n "<< i+1<< " coincide"<<endl;
            c++;
              if(c == 4){
                cout<<"Felicidades! su numero es capicua"<<endl;
            }
         }
         else{
            cout<< "No coincide, no es capicua"<<endl;
            return 0;
         }
    }



    return 0;
}
