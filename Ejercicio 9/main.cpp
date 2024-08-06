#include <iostream>

using namespace std;

int main()
{
    /*
    Dados un mes y el año correspondiente informar cuantos días tiene el mes.
    */
    int anio, mes, fecha;

    cout << "Ingrese un mes y un año" << endl;
    cin>> mes>> anio;

    switch(mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout<<"Tiene 31 dias"<<endl;
        break;
    case 02:
        if(anio%4 == 0)
        {
            cout<<"Tiene 29 dias"<<endl;
            cout<<"Es año bisiesto!!"<<endl;
        }
        else
        {
            cout<<"Tiene 28 dias"<<endl;
        }
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        cout<<"Tiene 30 dias"<<endl;
        break;
    default:
        cout<<"Ese mes no existe"<<endl;
        break;
    }

    return 0;
}
