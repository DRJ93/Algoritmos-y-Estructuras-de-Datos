#include <iostream>
#include <conio.h>
using namespace std;
/*
9. Se realiza una votación en el ámbito de CABA. Ud. debe hacer un programa que
maneja el conteo de votos.
a)Implementar una lista doblemente enlazada de mesas escrutadas. Cada mesa debe
contener:
- Nro. de mesa.
- Cantidad de votos partido 1.
- Cantidad de votos partido 2.
Confeccionar un subprograma que solicite los datos de una mesa al usuario e inserte la
la misma en la lista de manera ordenada ascendentemente por nro. de mesa.

b) Suponiendo que en CABA hay 1000 escuelas y que cada escuela contiene:
- Id de escuela (un número entero identificador de la escuela).
- Nombre de la escuela (hasta 100 caracteres).
- Nro. de Comuna
- Lista de mesas escrutadas.
Extienda el programa anterior para que, al crear una nueva mesa también solicite el
identificador de la escuela. Si la escuela no existe en la lista de escuelas debe crear el
nodo de escuela y luego insertarle la mesa en la sublista de mesas. Si la escuela existe
debe insertar directamente la mesa en su sublista.
*/
/*===== DECLARACION DE STRUCTS MESAS =====*/
struct Mesa{
    int numero = -1;
    int CantidadVotosPartidoUno;
    int CantidadVotosPartidoDOS;
};
struct NodoMesaDE{
    Mesa mesa;
    NodoMesaDE *ant = NULL;
    NodoMesaDE *sgte = NULL;
};
/*===== PRIMITIVAS DE=====*/
void InsertarOrdenado(Mesa m, NodoMesaDE *&listaDE) {
    //Creo el nuevo nodo con todo lo que implica. carga la info. el ant y el sgte estan en null por declarion del nodo.
    NodoMesaDE *nuevo = new NodoMesaDE();
    nuevo->mesa = m;
    if (!listaDE) { // Lista vacía
        listaDE = nuevo;
        return;
    }
    NodoMesaDE *aux = listaDE;
    // Inserción al inicio (antes del primer nodo)
    if (m.numero < aux->mesa.numero) {
        nuevo->sgte = aux;
        aux->ant = nuevo;
        listaDE = nuevo;
        return;
    }
    // Recorrer la lista para encontrar la posición de inserción
    while (aux->sgte && aux->sgte->mesa.numero < m.numero) {
        aux = aux->sgte;
    }
    // Inserción al final
    if (!aux->sgte) {
        aux->sgte = nuevo; //Esto mete al nuevo nodo en la lista.
        nuevo->ant = aux;
        return;
    }
    // Inserción en el medio
    //No hace falta otro if, porque si llega a entrar en cualquier if, al terminar, corta la ejecucion.
    nuevo->sgte = aux->sgte;
    nuevo->ant = aux;
    aux->sgte->ant = nuevo;
    aux->sgte = nuevo;
}
/*====== PUNTO 9.B ======= ESCUELAS*/
/*=====DECLARACION DE STRUCTS======*/
struct Escuela{
    int id = -1;
    char Nombre[100] = {0, 0, 0};
    int Comuna;
    NodoMesaDE *ListaMesasEscrutadas = NULL;
};
struct NodoEscuela{
    Escuela escuela;
    NodoEscuela *sgte = NULL;
};
/*===== PRIMITIVAS LISTAS SE =======*/
void InsertarNodoSE(NodoEscuela *&lista, Escuela e, Mesa m){
    NodoEscuela *nuevo = new NodoEscuela();
    nuevo->escuela = e;
    InsertarOrdenado(m, nuevo->escuela.ListaMesasEscrutadas);
    if (!lista) { // Lista vacía
        lista = nuevo;
        return;
    }

    nuevo ->sgte = lista;
    lista = nuevo;

}
void BuscarEscuela(NodoEscuela *&lista, Escuela e, Mesa m){
    NodoEscuela *a = lista;
    while(a){
        if(a->escuela.id == e.id){
            InsertarOrdenado(m, a->escuela.ListaMesasEscrutadas);
            return;
        }
        a = a ->sgte;
    }
    if(!a){
        InsertarNodoSE(lista,e, m);
    }
    a = lista;
    while( a && a->escuela.id != e.id){
        a = a->sgte;
    }
     return;
}
/*========= INGRESO DE DATOS ===========*/
void IngresarDatosEscuela(Escuela &x){
    cout<<"Ingrese el id de la escuela : ";
    cin>> x.id;
    cout<<endl<<"Nombre de la escuela: ";
    cin.ignore();
    cin.getline(x.Nombre, 100);
    cout<<endl<<"Comuna de la escuela: ";
    cin>>x.Comuna;
    return;
}
void IngresarDatosMesa( Mesa &y){

    cout<<endl<<"Ingrese el numero de mesa: ";
    cin>> y.numero;
    cout<<endl<<"Numero de votos del partido 1: ";
    cin>> y.CantidadVotosPartidoUno;
    cout<<endl<<"Numero de votos del partido 2: ";
    cin>> y.CantidadVotosPartidoDOS;
    return;
}
/* =========== LISTADO DE DATOS =============*/
void ListarMesas(NodoMesaDE *m){
     cout<<"===== Mesas ====="<<endl;
     while(m){
                cout<<"Mesa nro: "<< m->mesa.numero<<endl;
                cout<<"Cantidad de votos del partido Uno: "<<m->mesa.CantidadVotosPartidoUno<<endl;
                cout<<"Cantidad de votos del partido Dos: "<<m->mesa.CantidadVotosPartidoDOS<<endl;
                m = m->sgte;
            }
            return;
}
void ListarEscuelas(NodoEscuela *l){
    while(l){
            cout<<"Id de la escuela : "<<l->escuela.id<<endl;
            cout<<"Comuna de la escuela: "<<l->escuela.Comuna<<endl;
            cout<<"Nombre de la escuela: "<<l->escuela.Nombre<<endl;
            ListarMesas(l->escuela.ListaMesasEscrutadas);

        l = l->sgte;
    }

}


int main()
{
    NodoEscuela *ListaEscuelas = NULL;
    Escuela x;
    Mesa y;
    for(int i = 0; i<3; i++){
        IngresarDatosEscuela(x);
        IngresarDatosMesa(y);
        BuscarEscuela(ListaEscuelas, x, y);
    }
    ListarEscuelas(ListaEscuelas);
    /* === PRUEBAS DEL PUNTO 9.A ====*/
    /*
    NodoMesaDE *listaMesasDE = NULL;
    Mesa m1, m2, m3, m4;
    m1.numero = 1;
    m1.CantidadVotosPartidoUno = 3;
    m1.CantidadVotosPartidoDOS = 5;

    m2.numero = 2;
    m2.CantidadVotosPartidoUno = 6;
    m2.CantidadVotosPartidoDOS = 1;

    m3.numero = 3;
    m3.CantidadVotosPartidoUno = 2;
    m3.CantidadVotosPartidoDOS = 3;

    m4.numero = 4;
    m4.CantidadVotosPartidoUno = 5;
    m4.CantidadVotosPartidoDOS = 1;

    InsertarOrdenado(m1, listaMesasDE);
    InsertarOrdenado(m3, listaMesasDE);
    InsertarOrdenado(m4, listaMesasDE);
    InsertarOrdenado(m2, listaMesasDE);
*/
    return 0;
}
