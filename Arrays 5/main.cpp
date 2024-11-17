#include <iostream>
#include <conio.h>
using namespace std;
/*
Hacer un programa que permita realizar la suma y el producto de dos
vectores. El usuario deberá poder elegir el tamaño del vector (entre 2 y 10
valores).
*/
void inicializarVec(int v[], int tam, int neutro)
{
    for(int i = 0; i<tam; i++)
    {
        v[i] = neutro;
    }
}

void sumarVec(int v1[], int v2[], int tamN, int tamM, int vecSuma[], int vecSumadosTam)
{
    int i = 0;
    inicializarVec(vecSuma, vecSumadosTam, 0);
    while(i<tamN && i<tamM)
    {
        vecSuma[i] = v1[i] + v2[i];
        i++;
    }
    return;
}
void multiVec(int v1[], int v2[], int tamN, int tamM, int vecMulti[], int vecMultiTam)
{
    int i = 0;
    inicializarVec(vecMulti, vecMultiTam, 1);
    while(i<tamN && i<tamM)
    {
        vecMulti[i] = v1[i] * v2[i];
        i++;
    }
    return;
}


int main()
{
    int n, m, k, dato;
    int elementosV1 = 0;
    int elementosV2 = 0;
    cout << "Ingrese el tamaño del vector n 1:" << endl;
    cin>> n;
    cout << "Ingrese el tamaño del vector n 2:" << endl;
    cin>> m;
    /*Esto es para saber la cantidad de elementos que esperan en el vector de destino.*/
    if (n>m)
        k = m;
    else
        k = n;

    int v1[n], v2[m], vecSumados[k], vecMultiplicados[k];

    for(int i = 0; i < n; i++)
    {
        cout<<"El v1 en la posicion ["<<i<<"] es "<< v1[i]<<endl;
    }
    for(int i = 0; i < m; i++)
    {
        cout<<"El v2 en la posicion ["<<i<<"] es "<< v2[i]<<endl;
    }
    /*Menu*/
    char opcion;
    do
    {
        cout<< "Elija una opcion"<< endl;
        cout<< "a. Sumar vectores"<<endl;
        cout<< "b. Multiplicar Vectores"<<endl;
        cout<<"c. Ingresar valores en v1"<<endl;
        cout<<"d. Ingresar valores en v2"<<endl;
        cout<<"e. Inicializar vectores en 0"<<endl;
        cout<< "Esc. Salir"<<endl;
        do
        {

            opcion = getch();
        }
        while(opcion != 27 && opcion != 'a'&& opcion !='A'
                && opcion != 'b' && opcion != 'B'
                && opcion != 'c' && opcion != 'C'
                && opcion != 'd' && opcion !='D'
                && opcion != 'e' && opcion != 'E'
                );
        switch (opcion)
        {
        case 'a':
        case 'A':
            sumarVec(v1, v2, n, m, vecSumados, k);
            for(int i = 0; i < k; i++)
            {
                cout<<"El resultado de la suma en la posicion ["<<i<<"] de ambos vectores es: "<< vecSumados[i]<<endl;
            }
    break;
        case 'b':
        case 'B':
            sumarVec(v1, v2, n, m, vecMultiplicados, k);
            for(int i = 0; i < k; i++)
            {
                cout<<"El resultado del producto entre los elementos de la posicion ["<<i<<"] de los vectores es: "<< vecMultiplicados[i]<<endl;
            }
break;
        case 'c':
        case 'C':
            cout<<"Ingrese el valor a añadir"<<endl;
            cin>> dato;

            if(elementosV1<n)
            {
                v1[elementosV1] = dato;
                cout<<"El valor se añadio correctamente"<<endl;
                elementosV1++;
            }
            else
            {
                cout<<"Error, el vector esta completo."<<endl;
            }
break;
        case 'd':
        case 'D':
            cout<<"Ingrese el valor a añadir"<<endl;
            cin>> dato;

            if(elementosV1<m)
            {
                v2[elementosV2] = dato;
                cout<<"El valor se añadio correctamente"<<endl;
                elementosV2++;
            }
            else
                cout<<"Error, el vector esta completo."<<endl;

break;
        case 'e':
        case 'E':
            cout<< "los vectores se inicializaron correctamente."<<endl;
            inicializarVec(v1, n, 0);
            inicializarVec(v2, m, 0);
               for(int i = 0; i < n; i++)
    {
        cout<<"El v1 en la posicion ["<<i<<"] es "<< v1[i]<<endl;
    }
    for(int i = 0; i < m; i++)
    {
        cout<<"El v2 en la posicion ["<<i<<"] es "<< v2[i]<<endl;
    }
        case 27:
            return 0;
        }
    }
    while(opcion != 27);


    return 0;
}
