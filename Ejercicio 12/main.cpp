#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    cout << "Se van a mostrar todos lo numeros naturales menores a 100"<< endl;
    for(int i = 1; i<=100; i++){
        cout<< i << endl;
        sum += i;
    };
    cout<< sum<< " Es su sumatoria" <<endl;
    return 0;
}
