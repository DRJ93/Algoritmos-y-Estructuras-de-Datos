#include <iostream>
#include <conio.h>
using namespace std;
/*Se leen las letras de una palabra carácter a carácter. El último carácter que
ingresa es la barra de dividir(/), que indica que la palabra ha finalizado.
Escribir un programa que imprima la palabra en el orden que se ingresó y
en sentido inverso (por ejemplo: pera arep, la palabra podrá tener hasta 20
caracteres)*/


int main()
{
    char v[20];
    char c;
    int i = 0;
    cout << "Ingrese una palabra (Max. 20 caracteres)" << endl;
    c = getche();
    while( c  != '/'){
        v[i] = c;
        i++;
        c = getche();
    }
       for (int j=i-1; j>=0; j--)
            cout << v[j];

/*-----RECORDATORIOS-----------*/
/*
Siempre que realices los ejercicios inclui las librerias conio.h e iostream.

Es una funcion de conio.h.
getche(): Lee un solo carácter desde el teclado y lo muestra en la pantalla.
          No espera a que el usuario presione Enter.

*/
    return 0;
}
