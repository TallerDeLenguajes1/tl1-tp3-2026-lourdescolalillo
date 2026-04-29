#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//FUNCIONES
void mostrarPersonas(char *nombres[],int cantidad);
int main()
{
    //vector con 5 punteros, cada uno para un nombre
    char *nombres_personas[5];
    //borrador para guardar temporalmente los datos
    char buff[50];

    int i;
    int largo = 0;
    printf("\nINGRESO DE NOMBRES\n");
    for ( i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre #%d:",i + 1);

        //uso gets para cargar un arreglo con una frase
         gets(buff);

         //mido el largo de la frase usando la funcion strlen(sumo 1 porque esta funcion no lee el ultimo caracter)
         largo = strlen(buff) + 1;

         //reservo la memoria exacta que voy a necesitar
         nombres_personas[i] = (char*) malloc(largo* sizeof(char));

         //copio lo de mi borrador a mi espacio reservado
         strcpy(nombres_personas[i],buff);
    }

    mostrarPersonas(nombres_personas,5);
    return 0;
}

void mostrarPersonas(char *nombres[],int cantidad)
{
    int i;
    printf("\nLISTA DE PERSONAS\n");

    for(i = 0; i < cantidad; i++)
    {
        printf("nombre de la persona #%d: %s\n",(i + 1),nombres[i]);
    }

}