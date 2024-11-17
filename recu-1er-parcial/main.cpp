#include <iostream>
#include <conio.h>
using namespace std;

/*
tipo de embarcaciones = 0:sanitario;
                        1:pesquero;
                        2:Buque Tanque;
                        3:Buque Carga;
                        4:Crucero turistico;

   puerto[10]
   puerto[0] => tipo 0;
   puerto[1] => tipo 2;
   puerto[2] => tipo 1;
   puerto[3] => tipo 1;
   puerto[4] => tipo 3;
   puerto[5] => tipo 3;
   puerto[6] => tipo 4;
   puerto[7], [8], [9] => -1;
*/
struct embarcacion
{
    int identificacion;
    int tipo;
};
void inicializarTabla(int tabla[][10], int filas, int columnas)
{
    for(int i = 0; i<filas; i ++)
    {
        for(int j = 0; j<columnas; j++)
        {
            tabla[i][j] = 0;
        }

    }
    return;
}
void AsignarDiqueEmbarcacion(int puerto[], int tamPuerto, int tabla[][10], int filas
                             , int columnas, int ident_embarcacion, int tipo_embarcacion)
{

    switch(tipo_embarcacion)
    {
    case 0:
        if(puerto[0]< 5)
        {
            tabla[puerto[0]][0]= ident_embarcacion;
            puerto[0]++;
        }
        else if(puerto[0] == 5 && puerto[6]<5)
        {
            tabla[puerto[6]][6]= ident_embarcacion;
            puerto[6]++;
        }
        else if(puerto[6] == 5 && puerto[7]<5)
        {
            tabla[puerto[7]][7]= ident_embarcacion;
            puerto[7]++;
        }
        else if(puerto[7] == 5 && puerto[8]<5)
        {
            tabla[puerto[7]][7]= ident_embarcacion;
            puerto[7]++;
        }
        break;
    case 1:
        if(puerto[2]< puerto[3] && puerto[2]<5)
        {
            tabla[puerto[2]][2]= ident_embarcacion;
            puerto[2]++;
        }else if(puerto[3]<5){
            tabla[puerto[3]][3]= ident_embarcacion;
            puerto[3]++;
        }
        else if((puerto[2] == 5 && puerto[3] == 5)&& puerto[6]<5)
        {
            tabla[puerto[6]][6]= ident_embarcacion;
            puerto[6]++;
        }
        else if(puerto[6] == 5 && puerto[7]<5)
        {
            tabla[puerto[7]][7]= ident_embarcacion;
            puerto[7]++;
        }
        else if(puerto[7] == 5 && puerto[8]<5)
        {
            tabla[puerto[7]][7]= ident_embarcacion;
            puerto[7]++;
        }
        break;

    case 2:
        if(puerto[1]< 5)
        {
            tabla[puerto[1]][1]= ident_embarcacion;
            puerto[1]++;
        }
        else if(puerto[1] == 5 && puerto[6]<5)
        {
            tabla[puerto[6]][6]= ident_embarcacion;
            puerto[6]++;
        }
        else if(puerto[6] == 5 && puerto[7]<5)
        {
            tabla[puerto[7]][7]= ident_embarcacion;
            puerto[7]++;
        }
        else if(puerto[7] == 5 && puerto[8]<5)
        {
            tabla[puerto[7]][7]= ident_embarcacion;
            puerto[7]++;
        }

        break;
    case 3:
        if(puerto[4]< puerto[5] && puerto[4]<5)
        {
            tabla[puerto[4]][4]= ident_embarcacion;
            puerto[4]++;
        }
        else if( puerto [5] < 5)
        {
            tabla[puerto[5]][5]= ident_embarcacion;
            puerto[5]++;
        }
        else if((puerto[4] == 5 && puerto[5] == 5) && puerto[6]<5)
        {
            tabla[puerto[6]][6]= ident_embarcacion;
            puerto[6]++;
        }
        else if(puerto[6] == 5 && puerto[7]<5)
        {
            tabla[puerto[7]][7]= ident_embarcacion;
            puerto[7]++;
        }
        else if(puerto[7] == 5 && puerto[8]<5)
        {
            tabla[puerto[7]][7]= ident_embarcacion;
            puerto[7]++;
        }


        break;
    case 4:
        if(puerto[6]< 5)
        {
            tabla[puerto[6]][6]= ident_embarcacion;
            puerto[6]++;
        }
        else if(puerto[6] == 5 && puerto[7]<5)
        {
            tabla[puerto[7]][7]= ident_embarcacion;
            puerto[7]++;
        }
        else if(puerto[7] == 5 && puerto[8]<5)
        {
            tabla[puerto[8]][8]= ident_embarcacion;
            puerto[8]++;
        }
        else if(puerto[8] == 5 && puerto[9]<5)
        {
            tabla[puerto[9]][9]= ident_embarcacion;
            puerto[9]++;
        }
        break;

    }

    return;
}
/*-------------Para verificar-----------------*/
void mostrarTabla(int tabla[][10],int filas,int columnas)
{
    for(int i = 0; i < filas; i ++)
    {
        for(int k = 0; k < columnas; k++)
        {
            cout<<tabla[i][k]<<"\t";
        }
        cout<<endl;
    }
    return;
}
void mostrarEmbarques(embarcacion e[], int tam){
    for(int i = 0; i<tam; i++){
        cout<<"Datos de la embarcacion n"<< i<<endl;
        cout<< "Identificacion :"<< e[i].identificacion<<endl;
        cout<<"tipo : "<< e[i].tipo<<endl;
    }

}
/*-----------Para autocompletar las embarcaciones---------*/
void completarEmbarcaciones(embarcacion e[], int tam){
    for(int i = 0; i<tam; i++){
        for(int j = 0; j<5; j++){
            e[i].identificacion = i+1;
            e[i].tipo = i;
            if (i>5){
                e[i].tipo = i-5;
            }
        }

    }
    return;
}

int buscarEmbarcacion(int t[][10], int filas, int columna_donde_buscar, int identificacion_embarcacion ){
    for(int i = 0; i<filas; i++){
        if(t[i][columna_donde_buscar] == identificacion_embarcacion)
            return i;
    }
    return -1;
}
int main()
{
    int puerto [10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int tablaEmbarcaciones[5][10];
    embarcacion e[100];

    inicializarTabla(tablaEmbarcaciones, 5, 10);
    /*mostrar tabla*/
    cout<<"-------------Tabla cargada-------------"<<endl;
    mostrarTabla(tablaEmbarcaciones, 5, 10);
    completarEmbarcaciones(e, 20);
    mostrarEmbarques(e, 20);
    for(int i = 0; i<20; i++ ){
    AsignarDiqueEmbarcacion(puerto, 10, tablaEmbarcaciones, 5, 10, e[i].identificacion, e[i].tipo);
    }
    cout<<"------------Tabla ordenada--------------"<<endl;
    mostrarTabla(tablaEmbarcaciones, 5, 10);
    cout << "La embarcacion buscada esta en la fila:" << endl;
    cout<<buscarEmbarcacion(tablaEmbarcaciones, 5, 6, 5)<<endl;

    return 0;
}
