//Crear un afuncion booleana que reciba 2 numros y diga si es par o impar

#include <iostream>
using namespace std;

bool Numero (int num);

int main () {

    int num, res;

    cout << "Ingresa un numero: ";
    cin >> num;

    res = Numero(num);

    if (res == true)
    {
        cout << "El numero " << num << " es par";
    }
    else
    {
        cout << "El numero " << num << " es impar";
    }

    return 0;

}

bool Numero (int num) {

    if (num % 2 == 0) 
    {
        return true;
    }
    else
    {
        return false;
    }

}