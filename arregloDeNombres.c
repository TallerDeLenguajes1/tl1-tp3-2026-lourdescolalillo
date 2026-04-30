#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//FUNCIONES
void mostrarPersonas(char *nombres[],int cantidad);
int buscarNombrePorClave(char *nombres[], int cantidad, char *palabra);
void buscarNombrePorId(char *nombres[],int cantidad, int id);
int main()
{
    //vector con 5 punteros, cada uno para un nombre
    char *nombres_personas[5];
    //borrador para guardar temporalmente los datos
    char buff[50];
    int i;
    int largo = 0;
    char clave[50];
    int id = 0;
    int id_nombre;
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

    //interfaz de menu interactivo

    
    int opcion;
    printf("Ingrese 1: Busqueda por ID - ingrese 2: Busqueda por clave\n");
    printf("ingrese opcion de busqueda:");
    scanf("%d", &opcion);
    
    if(opcion == 1)
    {

        //pedir el id para la funcion buscar
        printf("ingrese el id:");
        scanf(" %d",&id_nombre);

        buscarNombrePorId(nombres_personas,5,id_nombre);

            
    }else if(opcion == 2){
        //pido al usuario ingresar la palabra clave
        printf("ingrese la palabra clave:\n");
        gets(clave);
        id = buscarNombrePorClave(nombres_personas,5,clave);

        if(id != -1)
            {
                printf("se encontro una coincidencia: %s\n",nombres_personas[id]);
            }else{
                printf("no se encontro coincidencias");
            }
    }

    //libero la memoria
    for(i = 0; i < 5; i++) {
        free(nombres_personas[i]);
    }
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

int buscarNombrePorClave(char *nombres[], int cantidad, char *palabra)
{
    int i;
    for(i = 0; i < cantidad; i++)
    {
       if(strstr(nombres[i],palabra) != NULL)
        {
            return i;
        }
    }
    return -1;
}
void buscarNombrePorId(char *nombres[],int cantidad, int id)
{
    if(id >= 1 && id <= cantidad)
    {
        printf("nombre en id %d: %s\n",id ,nombres[id - 1]);
    }else{
        printf("no se encontro el valor buscado\n");
    }
}