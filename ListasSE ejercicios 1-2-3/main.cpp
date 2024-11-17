#include <iostream>

using namespace std;


/*
Utilizando las funciones de ListasSE provistas en clase haga un programa que permita
al usuario:
 Insertar un elemento ordenadamente en la lista
 Buscar el mayor elemento
 Calcular el promedio de la lista


*/
struct nodoListaSE
{
    int dato;
    nodoListaSE *sgte = NULL;
};



/*================== Primitivas ===============================*/
nodoListaSE *ObtenerUltimo(nodoListaSE * p)
{
    if (p)
    {
        while (p->sgte)
        {
            p = p->sgte;
        }
    }
    return p;

}
void InsertarAlFinal (nodoListaSE  *&n, int x) /*El puntero "raiz" se pasa por referencia cuando es potencialmente necesario cambiar el inicio de una lista*/
{
    nodoListaSE *nuevo= new nodoListaSE();
    nodoListaSE *ultimo= NULL;
    nuevo->dato=x;
    nuevo->sgte= NULL;
    if (n!=NULL)
    {
            ultimo = ObtenerUltimo(n);
            ultimo->sgte = nuevo; //crear nuevo nodo al final.
    }
    else
    {
        n= nuevo; //si la lista esta vacia, crea un nodo.
    }
    return;
}

void insertarOrdenado(nodoListaSE *&lista, int n)
{
    nodoListaSE *paux = lista;
    nodoListaSE *anterior = NULL;
    while(paux && paux->dato < n)  //El while es para encontrar la "posicion" en la que va el n a insertar
    {
        anterior = paux;
        paux = paux->sgte;
    }
    if(paux != lista)
    {
        anterior->sgte = new nodoListaSE();
        anterior->sgte->dato = n;
        anterior->sgte->sgte = paux;
    }
    else
    {
        lista = new nodoListaSE();
        lista ->dato = n;
        lista->sgte = paux;
    }

    return;
}

void mostrarLista ( nodoListaSE *inicio, nodoListaSE *paux)
{
    paux = inicio;
    while(paux)
    {
        cout<< "Dato: "<< paux->dato<<endl;
        cout<<"Direccion del sgte nodo : "<< paux->sgte<<endl;
        cout<<"============================"<<endl;
        paux = paux->sgte;
    }
    return;
}
float calcularProm(nodoListaSE *inicio, nodoListaSE *aux)
{
    int i = 0;
    int suma = 0;
    aux = inicio;
    while(aux)
    {
        suma += aux->dato;
        aux = aux->sgte;
        i++;
    }
    float prom = suma/i;
    return prom;
}
int buscarMayor(nodoListaSE *inicio, nodoListaSE *aux)
{
    int mayor = 0;
    aux = inicio;
    while(aux)
    {
        if( aux->sgte && aux->dato > aux->sgte->dato)  //Primero verifico que aux->sgte != NULL
        {
            mayor = aux->dato;
        }
        else if (aux->sgte && aux->dato < aux->sgte->dato)
        {
            mayor = aux ->sgte->dato;
        }
        aux = aux->sgte;
    }
    return mayor;
}
/*========= Ejercicio 2 ===========
Realice un procedimiento o función que al recibir dos listas como parámetro, devuelva
una tercer lista que concatene las mismas.

*/
nodoListaSE *concatenarListas(nodoListaSE *inicio1, nodoListaSE *inicio2)
{
    nodoListaSE *aux = NULL;
    aux = inicio1;
    nodoListaSE *listasConcatenadas = aux;
    if(aux)
    {
        while(aux ->sgte)
        {
            aux = aux->sgte;
        }
    }
    aux->sgte = inicio2;

    return listasConcatenadas;
}
/*========== Ejercicio 3 ==========
Haga un procedimiento que reciba los mismos parámetros del punto 2 pero devuelva
una tercer lista con el contenido de ambas intercalado (es decir un nodo de la lista 1
seguido por un nodo de la lista 2, si una lista se finaliza primero quedan todos los
demás nodos de la otra lista consecutivos)

*/
void intercalarListas(nodoListaSE *inicio1, nodoListaSE *inicio2, nodoListaSE *&intercaladas)
{
    nodoListaSE *aux = NULL;
    while(inicio1)
    {
        InsertarAlFinal(intercaladas, inicio1->dato);
        if(inicio2)
        {
            InsertarAlFinal(intercaladas, inicio2->dato);
            inicio2 = inicio2->sgte;
        }
        inicio1 = inicio1->sgte;
    }
    while(inicio2)
    {
        InsertarAlFinal(intercaladas, inicio2->dato);
        inicio2 = inicio2->sgte;
    }

    return;
}
int main()
{
    nodoListaSE *inicio = NULL;
    nodoListaSE *inicio2 = NULL;
    nodoListaSE *concatenadas = NULL;
    nodoListaSE *intercaladas = NULL;
    nodoListaSE *aux = NULL;
    cout<<"=======Lista 1=========="<<endl;
    cout<<endl;
    insertarOrdenado(inicio, 4);
    insertarOrdenado(inicio, 540);
    insertarOrdenado(inicio, 152);
    insertarOrdenado(inicio, 17);
    insertarOrdenado(inicio, 266);
    insertarOrdenado(inicio, 19);
    mostrarLista(inicio, aux);
    cout<<endl;
    cout<<endl;
    cout<<"=======Lista 2=========="<<endl;
    cout<<endl;
    insertarOrdenado(inicio2, 19);
    insertarOrdenado(inicio2, 89);
    insertarOrdenado(inicio2, 9);
    insertarOrdenado(inicio2, 50);
    mostrarLista(inicio2, aux);
    cout<<endl;
    cout<<endl;
    /*Ejercicio 2*/
    /*
    cout<<"=======Listas 1 y 2 concatenadas=========="<<endl;
    cout<<endl;
    concatenadas = concatenarListas(inicio, inicio2);
    mostrarLista(concatenadas, aux);
    */
    /*Ejercicio 3*/
    cout<< " ================ Listas 1 y 2 intercaladas ============="<<endl;
    cout<<endl;
    intercalarListas(inicio, inicio2, intercaladas);
    mostrarLista(intercaladas, aux);
    return 0;
}
