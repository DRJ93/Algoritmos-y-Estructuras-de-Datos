#include <iostream>

using namespace std;

int main()
{
    void mostrarMayor(int vec[], int tam);
    int vec[15];


    mostrarMayor(vec[], 15);
}
    void mostrarMayor(int vec[], int tam){
        int aux;
        for(int i = 0; i<=15; i++){
        cout<<"Ingrese el valor"<< i <<endl;
        cin>>vec[i];
    }
        for(int j = 0; j<tam-1;j++){
            for(int i = 0; i<tam-1-j; i++){
                if(vec[i]>vec[i+1])
                    aux = vec[i];
                    vec[i]= vec[i+1];
                    vec[i+1] = aux;
            }
        }
        cout<<vec[0]<<endl;
        return;
    }

