#include <iostream>
#include <conio.h>
using namespace std;
/*
Realice un programa que lea dos números enteros n1 y n2 y luego muestre un menú con las
opciones:
a – Sumar los números
b – Restar los números
c – Multiplicarlos
d – Realizar la división n1/n2
Esc - Salir

*/

void error(){//Mensaje de error en caso de que la division no sea realizable.
    cout<<"No es posible realizar la operacion"<<endl;
}

//las funciones de cada operacion respectiva.
int suma(int x, int y){
    return x + y;
};
int resta( int x, int y){
    return x-y;
};
int multiplicacion (int x,int  y){
    return x*y;
};
int division(int x, int y){
    //verifico que el valor por el cual dividir no sea 0
    if(y!=0)
        return x/y;
    error();//mensaje de error xd
}

char menu(){
    char op;

    cout<< "a – Sumar los números"<<endl;
    cout<<"b – Restar los números"<<endl;
    cout<<"c – Multiplicarlos"<<endl;
    cout<<"d – Realizar la división n1/n2"<<endl;
    cout<< "Esc - Salir"<< endl;
    //Este bucle permite ingresar valores hasta que se presione uno de las opciones
    do{
        op = getch();//El getch() es una funcion que pertece a la libreria conio.h. Permite leer valores sin necesidad de mostrarlos, ni apretar el enter (no funciona en linux ni MacOS xd)
    }
    while (op!= 'a'&& op!= 'A'  &&
           op!= 'b'&& op!= 'B' &&
           op!= 'c'&& op!= 'C' &&
           op!= 'd'&& op!= 'D' &&
           op!= 27);
    return op;
}

int main()
{
    int n1, n2;
    char oE;
    cout << "Ingrese n1 y n2 e indique que operacion desea realizar: " << endl;
    cin>>n1>> n2;


    do{//Este bulcle permite el ingreso valores hasta que se presione la opcion esc-salida
       oE = menu();//invoca la funcion menu.

        switch(oE){//dependiendo del valor leido arriba. Invoca a la funcion pertinente.
            case 'a':
            case 'A':
                cout<<"El valor de la suma es "<< suma(n1, n2)<<endl;
                break;
            case 'b':
            case 'B':
                cout<<"El valor de la resta es "<< resta(n1, n2)<<endl;
                break;
            case 'c':
            case'C':
                cout<<"El valor del producto es "<<multiplicacion(n1, n2)<<endl;
                break;
            case 'd':
            case 'D':
                cout<<"El valor del cociente es "<<division(n1, n2)<<endl;
                break;
        }
    }  while(oE!=27);

    return 0;
}
