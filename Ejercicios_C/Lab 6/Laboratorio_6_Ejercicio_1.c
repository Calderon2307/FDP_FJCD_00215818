//Laboratorio 6, Ejercicio 1
//FEDERICO JOSUE CALDERON DURAN 00215818

#include <stdio.h>
#include <string.h> //Libreria para utilizar las funciones que manipulan strings
#define N 500 //Valor global, N tendra siempre el valor de 500, para poder manipular todos los lugares adonde se encuentrede manera mas sencilla 

void cambio (char palabra[N]); //Prototipo de la funcion

int main () {

    char frase[N], palabra[50]; //Se declaran 2 arreglos de tipo string, uno contendra la frase, otro la palabra a buscar

    printf("\nIngrese una frase: "); //Se pide la frase, con un maximo de 500 caracteres
    fflush(stdin); //Como se ingresaran valores char, se limpia el buffer
    fgets(frase, N, stdin); //Se guarda toda la frase que el usuario ingrese, colocando adonde se guardara, el tamaño que tiene el arreglo y el metodo por el cual se ingresara el contenido (stdin = standard input)
    cambio(frase); //Se llama a la funcion y se le pasa todo el string

    printf("\nLa frase ingresada es:\n%s", frase); //Se imprime la frase para que el usuario pueda verla

    printf("\n\nQue palabra desea buscar en la frase anterior?\n: "); //Se pide la palabra que el usuario quiera buscar
    fflush(stdin); //Se vacia el buffer
    fgets(palabra, 50, stdin); //Se guarda la palabra
    cambio(palabra); //Se llama a la funcion y se le pasa el string

    if (strstr(frase, palabra) != NULL) //Mediante el uso de la funcion "strstr" se le manda la cadena de caracteres en la que debe buscar coma y luego la palabra que debe buscar, si encuentra la coincidencia devolvera un puntero si no la encuentra devolvera NULL, entonces SI lo que la funcion devuelve es DISTINTO a NULL ↓
    {
        printf("La palabra -%s- se encuentra en el string.", palabra); //Le notificara al usuario que se ha encontrado la palabra
    }
    else //Si lo que devuelve es igual a NULL ↓
    {
        printf("La palabra -%s- NO se encuentra en el string.", palabra); //Le notificara al usuario que la palabra NO se encuentra
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