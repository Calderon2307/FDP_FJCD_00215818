//Realizar un traductor de ingles a español y visceversa con un vector de estructuras

#include <stdio.h>
#include <string.h>
#define N 50 //Variable global, N tendra siempre el valor de 50, para no estarlo poniendo a cada rato

typedef struct
{
    char Ingles [N]; //Palabras en ingles
    char Español [N]; //Palabras en español
    int lleno; //Si ya no tiene cupo la estructura
}traductor;

traductor trad[N]; //AQUI SE CREA EL VECTOR DE ESTRUCTURAS, se han creado 50 estructuras por que ese es el valor de N, pero si se quieren mas, basta con poner el numero entre los corchetes como cualquier otro vector, solo que aqui se crearan estructuras.
//Se declara afuera de todo para hacerla de tipo global y de esta manera que la pueda utilizar cualquier funcion sin necesidad de declararla adentro.

void vacio ();
void añadir ();
void traducir ();
void tradu (int op);
void cambio (char palabra[N]);

int main () {

    int op; //Variable de opciones del menu para elegir si meter o traducir una palabra
    char key; //Variable para repetir el menu

    vacio (); //TODAS las variables "lleno" se inicializan en 0

    do
    {
        do
        {
            printf("Elije que deseas hacer: \n\n1-) Añadir palabras al traductor.\n2-) Buscar la traduccion de una palabra.\n\n: ");
            scanf("%i", &op);
        } while (op < 1 || op > 2);
        
        switch (op)
        {
        case 1:
            añadir();
            break;
        case 2:
            traducir();
            break;
        
        default:
            break;
        }
        printf("Deseas realizar otra operacion?\nS / N\n: ");
        scanf("%c", &key);
    } while (key == 'S' || key == 's');

    return 0;
    
}

void vacio () {
    
    int i;

    for (i = 0; i < N; i++)
    {
        trad[i].lleno = 0;
    }
    
}

void añadir () {

    int i, aux;

    aux = 0; //Para ruta de escape

    for (i = 0; i < N && aux == 0; i++) //Se coloca el aux para que el bucle no se repita hasta el final las N veces, por que solo nos interesa guardar 1 palabra a la vez
    {
        if (trad[i].lleno == 0)
        {
            printf("Introduce la palabra en ingles: ");
            fflush(stdin);
            fgets(trad[i].Ingles, N, stdin); //recordar que fgets guarda al final como \n y no como \0 se cambiara ↓
            cambio(trad[i].Ingles);

            printf("Introduce la palabra en español: ");
            fflush(stdin);
            fgets(trad[i].Español, N, stdin);
            cambio(trad[i].Español);

            trad[i].lleno = 1;
            aux = 1; //Ruta de escape del bucle
        }
    }
    
}

void traducir () {

    int op;

    do
    {
        printf("Elije que deseas hacer: \n\n1-) Traducir de Ingles a Espanol.\n2-) Traducir de Espanol a Ingles.\n\n: ");
        scanf("%i", &op);
    } while (op < 1 || op > 2);
        
    switch (op)
    {
    case 1:
        tradu(op);
        break;
    case 2:
        tradu(op);
        break;
        
    default:
        break;
    }

}

void tradu (int op) {

    int i, j, esc;
    char aux[N], key;

    esc = 0; //RUTA DE ESCAPE

    printf("Introduce la palabra que deseas traducir: ");
    fflush(stdin);
    fgets(aux, N, stdin);
    cambio(aux);

    if (op == 1) //Traducira de Inlges a Español
    {
        for (i = 0; i < N && esc == 0; i++)
        {
            j = strcmpi(aux, trad[i].Ingles); //Comparara todas las palabras en ingles que se tengan obviando la diferencia entre mayusculas y minusculas
            if (j == 0) //si la palabra es igual, devolvera el valor 0
            {
                printf("La traduccion de %s es: %s.\n", trad[i].Ingles, trad[i].Español); //imprimira la palabra en ingles que sea igual y su respectiva traduccion
                esc = 1; //Le sumara 1 al esc para poder salir del bucle y que NO siga comparando
            }
             
        }
    }
    else if (op == 2)
    {
        for (i = 0; i < N && esc == 0; i++)
        {
            j = strcmpi(aux, trad[i].Español); //Comparara todas las palabras en español que se tengan obviando la diferencia entre mayusculas y minusculas
            if (j == 0) //si la palabra es igual, devolvera el valor 0
            {
                printf("La traduccion de %s es: %s.\n", trad[i].Español, trad[i].Ingles); //imprimira la palabra en español que sea igual y su respectiva traduccion
                esc = 1; //Le sumara 1 al esc para poder salir del bucle y que NO siga comparando
            }
        }    
    }
    
    
    

}

void cambio (char palabra[N]) {

    int i;

    for (i = 0; i < N; i++)
    {
        if (palabra[i] == '\n')
        {
            palabra[i] = '\0';
        }
        
    }
    
}

