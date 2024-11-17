#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#define N 3
#define M 3
#define P 3
using namespace std;
/*
11. Dada un matriz tridimensional de N x M x P se pide ordenarla de
menor a mayor

*/
/*Creo que seria hacer un bubblesort pero para una matriz, o
sea que por cada dimension de la matriz tendria que hacer uno(?*/

void ordenarMatriz(int matriz[N][M][P]){
       int aux;
        for ( int i = 0; i < N-1; i++){
            for(int j = 0; j < N-1-i; j++){

                if(matriz[j + 1][0][0] > matriz[j][0][0]){

                    aux = matriz[j][0][0];
                    matriz[j][0][0] = matriz[j + 1][0][0];
                    matriz[j +1 ][0][0] = aux;

                }

            }


        }
        for ( int i = 0; i < M-1; i++){
            for(int j = 0; j < M-1-i; j++){

                if(matriz[0][j+1][0] > matriz[0][j][0]){

                    aux = matriz[0][j][0];
                    matriz[0][j][0] = matriz[0][j+1][0];
                    matriz[0][j+1][0] = aux;

                }

            }


        }
             for ( int i = 0; i < P-1; i++){
            for(int j = 0; j < P-1-i; j++){

                if(matriz[0][0][j+1] > matriz[0][0][j]){

                    aux = matriz[0][0][j];
                    matriz[0][0][j] = matriz[0][0][j+1];
                    matriz[0][0][j+1] = aux;

                }

            }


        }

       return;
}
void llenarMatriz(int matriz[N][M][P]) {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < P; k++) {
                matriz[i][j][k] = rand() % 100; // Números aleatorios entre 0 y 99
            }
        }
    }
}

int main()
{
    int matriz[N][M][P];
    cout<<"Matriz Cargada"<<endl;
    llenarMatriz(matriz);
    //mostrar la matriz pre orden
    for( int i = 0; i<P; i++){
        for ( int j = 0; j<M; j++){
            for( int k = 0; k<N; k++){
                cout<< matriz[i][j][k]<<"\t\t\t";
            }

        }
    }
    cout<<endl<<"Matriz ordenada"<<endl;
    ordenarMatriz(matriz);
    //MOSTARR MATRIZ ORDENADAS
    for( int i = 0; i<P; i++){
        for ( int j = 0; j<M; j++){
            for( int k = 0; k<N; k++){
                cout<< matriz[k][j][i]<<"\t\t\t";
            }

        }
    }
 return 0;
}
