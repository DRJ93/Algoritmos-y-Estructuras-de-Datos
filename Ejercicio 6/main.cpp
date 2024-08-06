#include <iostream>

using namespace std;

int main()
{
    /*Dadas dos fechas informar cual es la más reciente. Determine cuales serían los
datos de entrada y las leyendas a informar de acuerdo al proceso solicitado.*/
    int f1, f2;
    cout<<"Ingrese dos fechas de la forma AAAAMMDD" <<endl;
    cin>> f1 >> f2;
    if(f1!= f2)
        {
            if(f1>f2)
                {
                    cout<< f1 <<" Es mas reciente que " << f2<<endl;
                }
            else
                {
                    cout<< f2 <<" Es mas reciente que " << f1<<endl;
                }
        }
    else
        {
            cout<<"Las fechas son iguales"<<endl;
        }

    return 0;
}
