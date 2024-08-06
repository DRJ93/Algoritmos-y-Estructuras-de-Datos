#include <iostream>

using namespace std;
    /*-------------------Consigna-----------------------*/
//    Desarrollar un procedimiento tal que dada una hora (HHMMSS) y un tiempo
//    también en formato HHMMSS devuelva la nueva hora que surge de sumar el tiempo a la hora
//    inicial, considere también si cambió el día.

//Declaro y defino el procedimiento
void Procedimiento(int h, int t){

        int seg = (((h%10000)%100) + ((t%10000)%100))%60;
        //cout<< seg<<endl;
        //Minutos más los bloques de 60 seg.
        int minu =(((h%10000)/100) + ((t%10000)/100))%60 +(((h%10000)%100) + ((t%10000)%100))/60;
        //cout<<minu<<endl;
        //Horas más bloques de 60min
        int hrs = ((h/10000 + t/10000) + (((h%10000)/100) + ((t%10000)/100))%60 +(((h%10000)%100) + ((t%10000)%100))/60)%24 ;
        //cout<<hrs<<endl;
        //Horas separadas en bloques de 24hrs.
        int dias = ((h/10000 + t/10000)+(((((h%10000)/100) + ((t%10000)/100))%60 +(((h%10000)%100) + ((t%10000)%100))/60)/60))/24;

        cout<< "la suma de horas es igual a "<< dias<< " dias "<< hrs<<" horas "<< minu <<" minutos y "<<seg << " segundos"<< endl;

}


int main()
{
//Declaro las variables del main.
    int hora, tiempo;
    cout<<"Ingrese su hora actual en HHMMSS"<<endl<<" Y luego Ingrese el tiempo que desea sumaarle"<<endl;
    cin>>hora>> tiempo;

    //Invoco el procedimiento
    //Recibe por parametro los datos que se ingresan
    Procedimiento(hora, tiempo);

    return 0;
}
