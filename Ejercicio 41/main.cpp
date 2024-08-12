#include <iostream>
#include<conio.h>
#include<stdio.h>
#include <locale.h>
using namespace std;

/*
De un censo realizado en una población se conocen los siguientes datos:
- Día de nacimiento (2 dig.)
- Mes (2 dig.)
- Año (4 dig.)
- Sexo ('M'=masc. 'F'=fem.)
Con estos datos de cada habitante se forma un lote finalizado con un día cero. Desarrollar el
programa que determine e imprima:
1) Cuántos nacimientos hubo en el mes de octubre de todos los años.
2) Cuántos nacimientos hubo antes del 9 de julio de 1990.
3) Cuántos nacimientos de mujeres hubo en la primavera del 1982.
4) Sexo de la persona más vieja (solo existe una).
*/

//Delcaro un struct con los datos que me dicen.
struct persona {
    int diaNacimiento;
    int mes;
    int anio;
    char sexo;
};

//creo una funcion que busque dentro del array de struct y devuelva cuantos elementos cumplen la condicion.
int buscarNacimientosMes(persona censo[], int tam, int mesBuscado){
    int nacimientos = 0;
    for(int i = 0; i < tam; i++){
        if (censo[i].mes == mesBuscado)
            nacimientos++;
    }
    return nacimientos;
}

//Esta funcion utiliza el for para recorrer el array e ir contando aquellos elementos que cumplan las condiciones.
int buscarNacimientosHastaUnaFecha(int anioBuscado, persona censo[], int tam, int diaNacimientoBuscado, int mesBuscado)
{
    int nacimientos = 0;
    for(int i = 0; i < tam; i++){
            if(censo[i].anio <= anioBuscado &&
               censo[i].mes< mesBuscado){
                    nacimientos++;
                    }
                else  if  (censo[i].mes == mesBuscado && censo[i].diaNacimiento <= diaNacimientoBuscado)                //Como es buscar/contar HASTA una fecha, se compara con <=
                {
                    nacimientos++;
                };
            };

        return nacimientos;
    }

int buscarNacimientosPrimavera(persona censo[], int tam, int anioBuscado){
    int nacimientosPrimavera;
    for(int i = 0; i < tam; i++){
        if((censo[i].anio == anioBuscado)&&
           ((censo[i].diaNacimiento >= 21 && censo[i].mes == 9)|| (censo[i].mes == 10)|| (censo[i].diaNacimiento <= 30 && censo[i].mes == 11)))
            nacimientosPrimavera++;
    }
    return nacimientosPrimavera;
};
char masViejo(persona censo[], int tam){
    char mayor;
    for(int i = 0; i < tam ; i++){
        for(int j = 0; j < tam; j++){
            if(censo[i].anio > censo[j].anio)
                mayor = censo[j].sexo;
            if ( censo[i].anio ==censo[j].anio && censo[i].mes > censo[j].mes)
                mayor = censo[j].sexo;
            if( censo[i].anio ==censo[j].anio && censo[i].mes ==censo[j].mes && censo[i].diaNacimiento > censo[j].diaNacimiento)
                mayor = censo[j].sexo;
            else
                mayor = censo[i].sexo;
    }
    return mayor;
    };

}
int ingresarDatos(persona censo[]){
    char stop;
    int i = 1;
    int j = 0;
    do{
            //Pido los datos que figuran el struct.
        cout<<"Ingrese los datos de la persona n°: "<< i<<endl;

        do{
            cout<< "Dia de nacimiento: ";
            cin>>censo[j].diaNacimiento;
        }while(censo[j].diaNacimiento<0 || censo[j].diaNacimiento >31);//Condiciones para que se ingresen fechas validas.
        cout<<endl;


        do{
            cout<<"Mes: ";
            cin>>censo[j].mes;
        }while(censo[j].mes < 0 || censo[j].mes> 12);
        cout<<endl;
        cout<<"Año: ";
        cin>>censo[j].anio;

        cout<<endl;
        do{
            cout<< "Sexo "<<endl;
            cout<< "M - Masculino " <<endl;
            cout<<"F - Femenino "<<endl;
            censo[j].sexo = getch();
            cout<<censo[j].sexo;
        }while(censo[j].sexo != 'M' &&
               censo[j].sexo != 'm'&&
               censo[j].sexo != 'F'&&
               censo[j].sexo != 'f');
        cout<<endl;
        if( j < 10 ){
        do{
            cout<<"desea seguir ingresando datos? presione 'S', para continuar. Y 'N', para detenerse"<<endl;
            stop = getch();
        }while(stop !='S'&& stop!='s'&&
               stop !='N'&& stop != 'n');
        if(stop == 'n'|| stop == 'N')
            return i;
        }

        i++;
        j++;
    }while(j < 10);
    return i;
}
char menu(){
    char op;

    cout<< "¿Que desea hacer con los datos?"<<endl;
    cout<< "a – Buscar Nacimientos en un mes especifico"<<endl;
    cout<<"b – Buscar Nacimientos hasta una determinada fecha"<<endl;
    cout<<"c – Buscar nacimientos de la primavera del año deseado"<<endl;
    cout<<"d – Buscar el sexo de la persona mas vieja"<<endl;
    cout<< "Esc - Salir"<< endl;
    //Este bucle permite ingresar valores hasta que se presione uno de las opciones
    do{
        op = getch();// El getch() es una funcion que pertece a la libreria conio.h. Permite leer valores sin necesidad de mostrarlos, ni apretar el enter (no funciona en linux ni MacOS xd)
    }//la condicion del while, es para asegurar que el valor ingresado sea admitido.
    while (op!= 'a'&& op!= 'A'  &&
           op!= 'b'&& op!= 'B' &&
           op!= 'c'&& op!= 'C' &&
           op!= 'd'&& op!='D' &&
           op!= 27);
    return op;
}
void seleccionarMes(int &mes){
        do{
            cout<<"Ingrese el mes: ";
            cin>>mes;
        }while(0 > mes && mes >12);
        return;
}
void seleccionarAnio(int &anio){
            do{
            cout<<"Ingrese el año: ";
            cin>>anio;
        }while(1000 > anio && anio >2024);
};
void seleccionarDia(int &dia){
      do{
            cout<<"Ingrese el dia: ";
            cin>>dia;
        }while(0 > dia && dia >31);
}
int main()
{
    setlocale(LC_ALL, "spanish");
    persona censo[10];
    int mesElegido;
    int anioElegido;
    int diaElegido;
    int tam = ingresarDatos(censo);
    char eleccion = menu();
    switch(eleccion){

        case 'a': case 'A':
            seleccionarMes(mesElegido);
            cout<<"El numero de nacimientos en el mes "<< mesElegido<<" es de: "<<buscarNacimientosMes(censo, tam, mesElegido)<<endl;
        break;
        case 'b': case 'B':
            seleccionarAnio(anioElegido);
            cout<<endl;
            seleccionarMes(mesElegido);
            cout<<endl;
            seleccionarDia(diaElegido);
            cout<<endl;
        cout<<"El numero de nacimientos hasta la fecha : "<< diaElegido<<"/"<<mesElegido<<"/"<<anioElegido<<" Es de: "<< buscarNacimientosHastaUnaFecha(anioElegido, censo, tam, diaElegido, mesElegido)<<endl;
        break;
        case 'c': case 'C':
            seleccionarAnio(anioElegido);
            cout<<"El numero de nacimientos durante esa primavera fue de: "<< buscarNacimientosPrimavera(censo, tam, anioElegido)<<endl;
        break;
        case 'd': case'D':
            cout<<"El sexo de la persona de mayor edad es: "<< masViejo(censo, tam)<<endl;
        break;
        case 27:
            break;
    }
    return 0;
}
