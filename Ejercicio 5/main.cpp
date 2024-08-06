#include <iostream>

using namespace std;

int main()
{

    //Dados dos valores enteros y distintos, emitir una leyenda apropiada que informe cuál es el
//mayor entre ellos.

    int x, y;
    cout << "Ingrese su 1er numero" << endl;
    cin>> x ;
    cout<< "Ingrese su 2do numero"<<endl;
    cin>> y;
    if(x !=y){
        if( x > y)
            {
                cout<< x << " Es mayor que "<< y <<endl;
            }
             else
                {
                    cout<< y<< " Es mayor que "<< x << endl;
                }
    }
    return 0;
}
