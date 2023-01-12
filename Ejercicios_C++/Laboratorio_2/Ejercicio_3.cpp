//Crear una funcion recursiva que sume los primeros n numeros

#include <iostream>
using namespace std;

int Suma (int a);

int main () {

    int num, res;

    cout << "Ingrese un numero: ";
    cin >> num;

    res = Suma(num);

    cout << "La suma de los primeros " << num << " numeros es: " << res;

    return 0;
}

int Suma (int a) {

    if (a == 0) return 0;
    else return a + Suma(a - 1);
}