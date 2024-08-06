#include <iostream>

using namespace std;

int main()
{
    /*
    Dados N y M números naturales, informar su producto por sumas sucesivas.
    */
    int N, M, prod;
    cout<< "Ingrese dos numeros naturales"<<endl;
    cin>> N>> M;
    for(int i = 0; i<=M; i++){
        prod += N;
    }
    cout<<"Es el valor de el producto "<< prod <<endl;
    return 0;
}
