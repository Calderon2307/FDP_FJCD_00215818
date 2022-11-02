//Un programa que almacene cuantas letras "a" tiene una palabra en la primera linea, cuantas "e" tiene en la segunda, cuantas "i" en la tercera, "o" en la cuarta, "u" en la quinta

#include <stdio.h>
#include <stdlib.h>

int main () {

    FILE *archivo;
    char letra;
    int a = 0, e = 0, i = 0, o = 0, u = 0;

    archivo = fopen ("Ejercicio3.txt", "r");

    if (archivo == NULL)
    {
        printf("No se ha encontrado el archivo.");
        exit(1);
    }

    printf("\n");

    while (letra != EOF)
    {
        letra = fgetc(archivo);
        if (letra == 'a' || letra == 'A')
        {
            a = a + 1;
        }
        else if (letra == 'e' || letra == 'E')
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
        printf("%c", letra);
        
    }

    fclose (archivo);

    printf("\n\nEn el texto anterior hay: \n\n%i letras a\n%i letras e\n%i letras i\n%i letras o\n%i letras u\n\n", a, e, i, o, u);
    
    return 0;
    
}