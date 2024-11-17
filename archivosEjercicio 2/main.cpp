#include <iostream>

using namespace std;

int main()
{

    int n;
    float x;
    float v[n];
    FILE* f;
    f = fopen("archivo_ej1", "wb");
        if(!f)
    {
        cout<<"ERROR"<<endl;
        return 55;
    }
    if(f){
    cout << "Ingrese la cantidad de valores que desea ingresar" << endl;
    cin>> n;
        for (int i = 0; i<n; i++){
            cout<< "Ingrese el valor "<< i+1<<endl;
            cin>> x;
            fwrite(&x, sizeof(float), 1, f);
            }
        fclose(f);
        }

    f = fopen("archivo_ej1", "rb");
        if(!f)
        {
            cout<<"ERROR"<<endl;
            return 55;
        }
    int i = 0;
    while(fread(&x, sizeof(float),1, f))
        {
            cout<< "byte " << i * sizeof(float)<< " = "<< x <<endl;
            i++;
        }
            fclose(f);

       /*Ejercicio 2
       Agregue al código anterior la funcionalidad para poder modificar un número, solicitando al
usuario en qué posición está el número que quiere modificar y cuál es el nuevo valor. Los
cambios deben ser guardados en el archivo.
       */

    f = fopen("archivo_ej1", "rb+");
        if(!f)
    {
        cout<<"ERROR"<<endl;
        return 55;
    }
    int op;
    float pi = 3.14;
    float nDato;

    cout<<"desea modificar algun valor? Ingrese = 1 para si, 0 para no."<<endl;
    cin>> op;
    if(op){
        cout<< "En que posicion se encuentra el valor a cambiar?"<<endl;
        cin>>op;
        op -= 1;
        cout<<"Ingrese el nuevo valor"<<endl;
        cin>>nDato;
        fseek(f, op * sizeof(float), SEEK_SET);
        fwrite(&nDato, sizeof(float), 1, f);
       fseek(f, 0, SEEK_SET);
        int i = 0;
        while(fread(&x, sizeof(float), 1, f)){
            cout<< "byte " << i * sizeof(float)<< " = "<< x<<endl;
            i++;
        }
            fclose(f);
    }
    return 0;
}

