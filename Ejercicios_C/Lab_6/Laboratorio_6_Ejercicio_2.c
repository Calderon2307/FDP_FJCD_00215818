//Laboratorio 6, Ejercicio 2
//FEDERICO JOSUE CALDERON DURAN 00215818

#include <stdio.h>
#include <string.h> //Libreria para utilizar las funciones que manipulan strings
#define N 50 //Valor global, N tendra siempre el valor de 500, para poder manipular todos los lugares adonde se encuentrede manera mas sencilla 

void cambio (char palabra[N]); //Prototipo de la funcion

int main () {

    char palabra[N], reves[N]; //Se declaran 2 strings, uno contendra la palabra ingresada por el usuario y el otro la palabra al reves
    int i, j, n;

    printf("\n\nUn PALINDROMO es una palabra que se lee igual al derecho (de izquierda a derecha) y al reves (de derecha a izquierda)\n\nIngrese una palabra para verificar si es un PALINDROMO o no\n: "); //Breve explicacion y se pide la palabra al usuario
    fflush(stdin); //Se limpia el buffer
    fgets(palabra, N, stdin); //Se guarda la palabra
    cambio(palabra); //Se llama a la funcion y se le pasa la palabra

    n = strlen(palabra); //Con esta funcion se obtiene el tamaño de la palabra sin contar el "\0" para poder utilizarlo mas adelante ↓
    j = 0; //Se declara un contador que ayudara para ingresar letra por letra en el string "reves"

    for (i = n-1; i >= 0; i--) //Sabiendo el tamaño de la palabra, podemos comenzar desde la ultima posicion y llegar hasta la 0
    {
        reves[j] = palabra[i]; //Se ira guardando letra por letra en el string "reves"
        j++; //Se aumentara en 1 el contador j que es de la posicion de "reves"
    }

    if (strcmpi(palabra, reves) == 0) //Se comparara la palabra ingresada por el usuario letra por letra, sin hacer diferencia entre mayusculas y minusculas para evitar problemas y la palabra al reves, si DEVUELVE un 0 las palabras son iguales
    {
        printf("La palabra -%s- es un PALINDROMO.", palabra); //Se le notifica al usuario
    }
    else //Si devuelve otro valor distinto a 0 ↓
    {
        printf("La palabra -%s- NO es un PALINDROMO.", palabra); //Se le notifica al usuario
    }
       
    return 0;

}


void cambio (char palabra[N]) { //Debido a que "fgets" SIEMPRE guarda como ultimo digito del string un "\n", medinte esta funcion se cambiara TODO "\n" que se encuentre en el string por un "\0"

    int i; //Se declara un contador

    for (i = 0; i < N; i++) //Se recorre todo el string
    {
        if (palabra[i] == '\n') //Si encuentra una coincidencia en la posicion
        {
            palabra[i] = '\0'; //La reemplazara por "\0"
        }    
    }    
}