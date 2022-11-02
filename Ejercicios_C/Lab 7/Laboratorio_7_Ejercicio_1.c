//Programa que escriba en un archivo los numeros positivos ingresados por el usuario y en otro archivo los negativos

#include <stdio.h>
#include <stdlib.h>

void Opcion1 ();
void Opcion2 ();

int main () {

    int x;

    do
    {
        printf("\n¿Que desea hacer?\n\n1.) Ingresar un numero\n2.) Ver numeros ingresados\n3.) Salir\n\n: ");
        scanf("%i", &x);
        if (x == 1)
        {
            Opcion1();
        }
        else if (x == 2)
        {
            Opcion2();
        }
        
    } while (x >= 1 && x <= 2);

    printf("\n\nS A L I E N D O. . .\n\n");
    
    return 0;

}

void Opcion1 () {

    FILE *archivo;

    int num, esc;

    printf("Ingrese un numero: ");
    scanf("%i", &num);

    if (num > 0)
    {
        archivo = fopen("Positivo.txt", "a");
        if (archivo == NULL)
        {
            printf("No se ha encontrado el archivo.");
            exit(1);
        }

        esc == 0;

        do
        {
            fprintf(archivo, "%i ", num);
            esc = 1;

        } while (esc == 0);

        fclose(archivo);
            
    }

    else if (num < 0)
    {
        archivo = fopen("Negativo.txt", "a");
        if (archivo == NULL)
        {
            printf("No se ha encontrado el archivo.");
            exit(1);
        }

        esc == 0;

        do
        {
            fprintf(archivo, "%i ", num);
            esc = 1;

        } while (esc == 0);

        fclose(archivo);
            
    }
    
}

void Opcion2 () {

    FILE *archivo;

    int op;
    char num;

    printf("¿Que archivo desea ver?\n1.) Positivos\n2.) Negativos\n: ");
    scanf("%i", &op);

    if (op == 1)
    {
        archivo = fopen ("Positivo.txt", "r");
        if (archivo == NULL)
        {
            printf("No se ha encontrado el archivo.");
            exit(1);
        }

        printf("\nLos numeros positivos ingresados por el usuario son: \n");

        while (num != EOF)
        {
            num = fgetc(archivo);
            printf("%c", num);
        }

        fclose(archivo);
        
    }

    else if (op == 2)
    {
        archivo = fopen ("Negativo.txt", "r");
        if (archivo == NULL)
        {
            printf("No se ha encontrado el archivo.");
            exit(1);
        }

        printf("\nLos numeros negativos ingresados por el usuario son: ");

        while (num != EOF)
        {
            num = fgetc(archivo);
            printf("%c", num);
        }

        fclose(archivo);
        
    }
    
}