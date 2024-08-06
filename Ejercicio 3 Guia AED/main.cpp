#include<iostream>
using namespace std;
/*
Dada un numero entero de la forma (AAAAMMDD), que representa una fecha
valida mostrar el dia, mes y año que representa
*/
int main(){
    int f;

    cout<<"Ingrese su fecha de la forma AAAAMMDD" <<endl;
    cin>>f;

    cout<< f/10000<<endl;
    cout<<( f%10000)/100<< endl;
    cout<<(f%10000)%100<<endl;

    return 0;
}
