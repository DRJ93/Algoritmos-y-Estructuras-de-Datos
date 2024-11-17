#include <iostream>

using namespace std;
/*
Escriba un programa que permita a un usuario ingresar n valores float y se guarden en un
archivo, el número n lo informa al comienzo del programa. Al finalizar el programa debe listar
todos los números guardados en el archivo.
*/
int main()
{
    int n;
    float v[n];
    FILE* f;
    f = fopen("archivo_ej1", "wb");
    if(f){
    cout << "Ingrese la cantidad de valores que desea ingresar0" << endl;
    cin>> n;

        for (int i = 0; i<n; i++){
            cout<< "Ingrese el valor "<< i+1<<endl;
            cin>> v[n];
            fwrite(v, sizeof(float), 1, f);
            }
        fclose(f);
        }
    else{
        cout<< "No se pudo crear/abrir el archivo"<<endl;
    }

    f = fopen("archivo.ej1", "rb");
    if(f){
            for(int i = 0; i<n;i++){
            fread(v, sizeof(float), 1, f);
            cout<< "byte " << i * sizeof(float)<< " = "<< v[i]<<endl;
            }
            fclose(f);
        }
       /*Ejercicio 2
       Agregue al código anterior la funcionalidad para poder modificar un número, solicitando al
usuario en qué posición está el número que quiere modificar y cuál es el nuevo valor. Los
cambios deben ser guardados en el archivo.
       */
    f = fopen("archivo.ej1", "rb+");
    int op;
    float x;
    cout<<"desea modificar algun valor? 1 : si, 0: no."<<endl;
    cin>> op;
    if(op && f){
        cout<< "En que byte se encuentra el valor a cambiar?"<<endl;
        cin>> op;
        fseek(f, op, SEEK_SET);

        cout<<"Ingrese el nuevo valor"<<endl;
        cin>>x;
        fwrite(&x, op, 1, f);
         for(int i = 0; i<n;i++){
            fread(&x, op, 1, f);
            cout<< "byte " << i * sizeof(float)<< " = "<< x<<endl;
            }
            fclose(f);
    }
    return 0;
}
