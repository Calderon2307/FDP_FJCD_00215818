//Un programa que almacene cuantas letras "a" tiene una palabra en la primera linea, cuantas "e" tiene en la segunda, cuantas "i" en la tercera, "o" en la cuarta, "u" en la quinta

#include <stdio.h>
#include <stdlib.h>

int main () {

    FILE *archivo; //Se declara una variable de tipo FILE
    char letra; //Se declara la variable en la que se iran guardando los caracteres que vaya leyendo la funcion "fgetc"
    int a = 0, e = 0, i = 0, o = 0, u = 0; //Variables a utilizar como contadores segun la letra que representan

    archivo = fopen ("Ejercicio3.txt", "r"); //Se abre el archivo

    if (archivo == NULL) //Si hay un error con la apertura dle archivo ↓
    {
        printf("No se ha encontrado el archivo."); //Se le notifica al usuario
        exit(1); //Termina el programa
    }

    printf("\n"); //Salto de linea

    while (letra != EOF) //Mientras la variable "letra" NO llegue al caracter EOF (final del archivo)
    {
        letra = fgetc(archivo); //Ira leyendo y gurdando caracter por caracter en la variable "letra"
        if (letra == 'a' || letra == 'A') //Si "letra" es igual a la vocal 'a' mayuscula o minuscula
        {
            a = a + 1; //Se le sumara 1 al contador de las letra 'a'
        }
        else if (letra == 'e' || letra == 'E') //Lo mismo que arriba con la letra 'a' ↑ y para todas las demas ↓
        {
            e = e + 1;
        }
        else if (letra == 'i' || letra == 'I')
        {
            i = i + 1;
        }
        else if (letra == 'o' || letra == 'O')
        {
            o = o + 1;
        }
        else if (letra == 'u' || letra == 'U')
        {
            u = u + 1;
        }
        printf("%c", letra); // Imprime el texto completo que se encuentra en el archivo
        
    }

    fclose (archivo); //Cierra el archivo

    printf("\n\nEn el texto anterior hay: \n\n%i letras a\n%i letras e\n%i letras i\n%i letras o\n%i letras u\n\n", a, e, i, o, u); //Muestra en pantalla TODOS los contadores con sus respectivos valores
    
    return 0;
    
}