//Dados 2 numeros, transformar al primer numero en el segundo, haciendo una serie de operaciones

#include <iostream>
using namespace std;

int Conversion (int a, int b);

int main () {

    int num1, num2, res;

    cout << "Ingrese el primer numero: ";
    cin >> num1;

    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    res = Conversion(num1, num2);

    cout << "Para transformar el numero " << num1 << " en el numero " << num2 << " hacen falta " << res << " operaciones";

    return 0;

}

int Conversion(int num1, int num2) {

    int i;

    if (num1 % 2 == 0 || num1 > num2) 
    {
        i = 0;
        do
        {
            if (num1 % 2 == 1)
            {
                num1 + 1;
            }
            num1/=2;
            i++;
        } while (num1 > num2);
        if (num1 < num2)
        {
            while (num1 < num2)
            {
                num1+=1;
                i++;
            }
        }
        
        
        return i;
    }
    else
    {
        i = 0;
        while (num1 < num2)
        {
            num1+=1;
            i++;
        }
        
        return i;
    }

}