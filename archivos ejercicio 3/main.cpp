#include <iostream>

using namespace std;
/*Dados dos archivos de enteros confeccione un programa que guarde en un tercer archivo el
contenido de ambos intercalado de a un número.*/
void apareo( ){

    FILE *f, *p, *q;
    f = fopen("archivo_ej1", "rb");
    p = fopen("archivo_ej2", "rb");
    q = fopen("intercalado", "wb");
    float x, y;
    while(fread(&x, sizeof(float), 1, f)){
        cout<< "Primer Archivo " << x<<endl;
    }
     while(fread(&y, sizeof(float), 1, p)){
        cout<< "Segundo Archivo " << y<<endl;
    }
    while(fread(&x, sizeof(float), 1, f) && fread(&y, sizeof(float), 1, p))
    {
        if(x<y)
        {
            fwrite(&x, sizeof(float), 1, q);
            fseek(p, -1 * sizeof(float), SEEK_CUR);
        }
        else
        {
                fwrite(&y, sizeof(float), 1, q);
                fseek(f, -1 * sizeof(float), SEEK_CUR);
        }
    }
    while(!feof(f)){ //agregar el ultimo elemento de f
        fwrite(&x, sizeof(float), 1, q);
        fread(&x, sizeof(float), 1, f);//leo para mover el puntero
    }
        while(!feof(p)){ //agregar el ultimo elemento de p
        fwrite(&y, sizeof(float), 1, q);
        fread(&y, sizeof(float), 1, p);//leo para mover el puntero
    }
       while(fread(&y, sizeof(float), 1, q)){
        cout<< " Archivo Intercalado" << y<<endl;
    }
    fclose(f);
    fclose(p);
    fclose(q);
    return;
}

int main()
{
    FILE *salida;
    apareo();
    salida = fopen("intercalado", "rb");
    float x;
    while(fread(&x, sizeof(float), 1, salida)){
        cout<< x <<endl;
    }
    return 0;
}
