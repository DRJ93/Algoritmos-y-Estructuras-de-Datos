#include <iostream>

using namespace std;
/* Confeccione una funci�n que reciba un n�mero entero n y devuelva el factorial de dicho
n�mero.
*/
int factorial(int n){
    if(n<= 1)
        return n;
    return n * factorial(n-1);
}

int main()
{
    int x;
    cout << "Ingrese un numero para calcular su factorial" << endl;
    cin>> x;
    cout<< "El factorial de "<< x << " es = "<< factorial(x)<<endl;
    return 0;
}
