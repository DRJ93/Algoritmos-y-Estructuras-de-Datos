#include <iostream>

using namespace std;
/*
En total hay 10 canchas.
*/

struct Cancha{
    int numero;
    float precioHoraAlquiler;
};

void totalAlqPorHora(Cancha vCanchas[], int n, int mHorasAlq[][7]){
//vCanchas = contiene n cantidad de canchas
//mHorasAlq[][] = cantidad de horas que fue alquilada una cancha cada dia de la semana.
//mostrar numero de cancha y total recibido por cancha en la semana.
for(int i = 0; i<n; i++){
    float totalRecaudado = 0;
    cout<<"Cancha n°"<< vCanchas[i].numero<<endl;

    for(int j = 0; j<7; j++){
       totalRecaudado += (mHorasAlq[i][j]*vCanchas[i].precioHoraAlquiler);
    }

}
return;
}
int main()
{
    Cancha vCanchas[10];
    cout << "Hello world!" << endl;
    return 0;
}
