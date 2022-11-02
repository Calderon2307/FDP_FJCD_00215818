//Programa que escriba en un archivo los numeros positivos ingresados por el usuario y en otro archivo los negativos

#include <stdio.h>
#include <stdlib.h>

void Opcion1 (); //Prototipo de funcion
void Opcion2 (); //Prototipo de funcion

int main () {

    int x; //Variable a utilizar para el menu

    do
    {
        printf("\n¿Que desea hacer?\n\n1.) Ingresar un numero\n2.) Ver numeros ingresados\n3.) Salir\n\n: "); //Menu 
        scanf("%i", &x);
        if (x == 1) //Si elije la opcion 1 ↓
        {
            Opcion1(); //Llama a la primera funcion
        }
        else if (x == 2) //Si elije la opcion 2 ↓
        {
            Opcion2(); //Llama la segunda funcion
        }
        
    } while (x >= 1 && x <= 2); //Mientras la opcion sea 1 o 2, el programa correra, si es otro numero o tecla, el programa acabara

    printf("\n\nS A L I E N D O. . .\n\n"); //Se le notifica al usuario que se esta saliendo del programa
    
    return 0;

}

void Opcion1 () { //Funcion en caso se elija la opcion 1 del menu ↑

    FILE *archivo; //Se declara una variable de tipo FILE

    int num, esc; //Variables a utilizar

    printf("Ingrese un numero: "); //Se le pide un numero al usuario para poder guardarlo en el archivo correspondiente
    scanf("%i", &num); //Se guarda  el numero ingresado por el usuario

    if (num > 0) //Si el numero es mayor que 0, tenemos que el numero es POSITIVO
    {
        archivo = fopen("Positivo.txt", "a"); //Se abre el archivo en el cual se iran guardando los numeros positivos que el usuario vaya ingresando
        if (archivo == NULL) //Si ocurre algun error al momento de mandar a abrir el archivo ↓
        {
            printf("No se ha encontrado el archivo."); //Se le notificara al usuario
            exit(1); //El programa terminara
        }

        esc = 0; //Ruta de escape para poder salir del while y solo ingresar un numero a la vez al archivo 

        do
        {
            fprintf(archivo, "%i ", num); //Ingresa el numero correspondiente al archivo
            esc = 1; //Ruta de esacape

        } while (esc == 0); //La variable "esc" ya no vale 0, por lo que el bucle termina

        fclose(archivo); //Se cierra el archivo
            
    }

    else if (num < 0) //Si el numero es menor que 0, tenemos que el numero es NEGATIVO
    {
        archivo = fopen("Negativo.txt", "a"); //Se abre el archivo en el cual se iran guardando los numeros positivos que el usuario vaya ingresando
        if (archivo == NULL)
        {
            printf("No se ha encontrado el archivo.");
            exit(1);
        }

        esc = 0;

        do
        {
            fprintf(archivo, "%i ", num);
            esc = 1;

        } while (esc == 0);

        fclose(archivo); //Se cierra el archivo
            
    }
    
}

void Opcion2 () { //Funcion en caso se elija la opcion 2 del menu ↑

    FILE *archivo; //Se declara una variable de tipo FILE 

    int op; //Varaible a utilizar para que el usuario ingrese una opcion del menu
    char num; //Variable a utilizar para guardar los caracteres de los archivos y mostrarlos

    printf("¿Que archivo desea ver?\n1.) Positivos\n2.) Negativos\n: "); //Menu
    scanf("%i", &op);

    if (op == 1) //Si elije la opcion 1
    {
        archivo = fopen ("Positivo.txt", "r"); //Se abre el archivo que contiene los numeros positivos ingresados por el usuario
        if (archivo == NULL) //Si hay un error ↓
        {
            printf("No se ha encontrado el archivo."); //Se le notifica al usuario
            exit(1); //Se termina el programa
        }

        printf("\nLos numeros positivos ingresados por el usuario son: \n");

        while (num != EOF) //Mientras el archivo no termine, es decir, mientras NO llegue al caracter "EOF"
        {
            num = fgetc(archivo); //Ira leyendo y guardando caracter por caracter en la variable "num"
            printf("%c", num); //Imprimira la variable "num" con cada caracter que esta tenga
        }

        fclose(archivo); //Cerrara el archivo
        
    }

    else if (op == 2) //Si elije la opcion 2
    {
        archivo = fopen ("Negativo.txt", "r"); //Se abre el archivo que contiene los numeros negativos ingresados por el usuario
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

        fclose(archivo); //Se cierra el archivo
        
    }
    
}