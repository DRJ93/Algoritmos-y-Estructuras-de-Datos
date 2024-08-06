#include <iostream>

using namespace std;
/*
Dado tres valores determinar e imprimir una leyenda según sea: “Forman
triangulo” o “No forman triangulo”
*/
int main()
{
    int x, y, z;
    cout << "Ingrese 3 valores" << endl;
    cin>> x>> y>> z;
    if((x + z >y) && (x+y>z) && (z+y>x))
        {
            cout<<"Forman un triangulo"<<endl;
        }
    else
        {
            cout<<"No forman un triangulo"<<endl;
        }
    return 0;
}
