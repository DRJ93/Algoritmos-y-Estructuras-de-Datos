#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

/*
 Realice una función que reciba los coeficientes de un polinomio de grado 2 y devuelva las
raíces del mismo siempre y cuando sean raíces reales.
(so, hacer la resolvente xd)
*/


//Como el ejercico pide devolver ambos valores, creo una estructura que haga posible devolverlos.
struct Raices
{
    double raiz1 = 0;
    double raiz2 = 0;
};


//Una funcion de Tipo Raices(o sea que devuelve algo de este tipo)
Raices resolvente(double a, double b, double c, double discriminante)
{
//Esta declaracion es donde se asentaran los datos obtenidos, para despues retornarlos.
  Raices reales;

//El metodo para resolverso es usando bhaskara o "la resolvente de funciones cuadraticas.
//Evalua si el valor del discriminantes es >= 0
//Esto es porque si este es < 0 las raices de dicha funcion, no existen o no son reales.
    if (discriminante >= 0)
    {
        double raizA = (-b + sqrt(discriminante))/(2*a);
        double raizB = (-b - sqrt(discriminante))/(2*a);
        //la funcion sqrt(), pertenece a la libreria math.h, sirve para calcular la raiz cuadrada.
        reales.raiz1 = raizA;
        reales.raiz2 = raizB;
        return reales;
    }

}

int main()
{
    double a, b, c, discriminante; //Declaro valores
    cout<<"Ingrese los coeficientes de un polinomio de grado 2"<<endl;
    cin>>a >> b>> c;//el usuario ingresa valores
    discriminante = (b*b)-4 *a * c;//Se calcula aca, para poder evaluar que mensaje mostrar. disc == 0 --> 1 raiz doble, disc > 0 --> 2 raices, disc < 0--> ninguna raiz/no real
    if (discriminante > 0)
        //muestra las dos raices del polinomio.
        cout<<"la primera raiz es = "<<resolvente(a,b,c,discriminante).raiz1<<" y la segunda raiz es = "<<resolvente(a,b,c,discriminante).raiz2<<endl;
    else
         cout<<"Las raices no existen, o no son reales"<<endl;

    return 0;
}
