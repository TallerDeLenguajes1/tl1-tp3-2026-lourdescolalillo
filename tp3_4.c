#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};  
typedef struct producto { 
int ProductoID;      //Numerado en ciclo iterativo  
int Cantidad;        // entre 1 y 10 
char *TipoProducto;   // Algún valor del arreglo TiposProductos       
float PrecioUnitario; // entre 10 - 100 
}producto;  

typedef struct cliente {   
int ClienteID;               // Numerado en el ciclo iterativo
char *NombreCliente;          // Ingresado por usuario 
int CantidadProductosAPedir; // (aleatorio entre 1 y 5) 
struct producto *Productos;         //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”  
}cliente;

float calcularCosto(producto p);

int main() {
    srand(time(NULL));
    int cantidadClientes ;
    char buff[100];
    int i,j;

    printf("ingrese la cantidad de clientes:");
    scanf("%d", &cantidadClientes);
    while(getchar()!='\n');

    if(cantidadClientes < 1 )
    {
        printf("Cantidad no valida\n");
        return 1;
    }

    cliente *clientes = (cliente*)malloc(cantidadClientes * sizeof(cliente));

    //CARGA DE DATOS
    for(i = 0 ; i < cantidadClientes ; i++)
    {
        clientes[i].ClienteID = i + 1;
        printf("\nel nombre del cliente #%d:\n",clientes[i].ClienteID);
        gets(buff);
        clientes[i].NombreCliente = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(clientes[i].NombreCliente,buff);

        clientes[i].CantidadProductosAPedir = rand () % 5 + 1;
        clientes[i].Productos = (producto*)malloc(clientes[i].CantidadProductosAPedir * sizeof(producto));
        
        for(j = 0 ; j < clientes[i].CantidadProductosAPedir ; j++)
        {
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = rand() % 10 + 1;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
            clientes[i].Productos[j].PrecioUnitario = rand () % 91 + 10;
        }
    }
    
    //MOSTRAR DATOS Y CALCULOS
    printf("\n===== RESUMEN =====\n");
    for(i = 0 ; i < cantidadClientes ; i++)
    {
        float totalPorCliente = 0;
        printf("\ncliente: %s (ID #%d)\n",clientes[i].NombreCliente,clientes[i].ClienteID);

        for(j = 0 ; j < clientes[i].CantidadProductosAPedir; j++)
        {
            float costoTotalPorProducto = calcularCosto(clientes[i].Productos[j]);
            totalPorCliente = totalPorCliente + costoTotalPorProducto;

            printf("\nproducto: %s | cantidad: %d | precio unitario: $%.2f | Total del producto: $%.2f\n",clientes[i].Productos[j].TipoProducto,clientes[i].Productos[j].Cantidad,clientes[i].Productos[j].PrecioUnitario,costoTotalPorProducto);

        }
        printf("\nel total a pagar es: $%.2f\n",totalPorCliente);
    }
    //librerar memoria
    for(i = 0 ; i < cantidadClientes ; i++)
    {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    free(clientes);

    return 0;

}

float calcularCosto(producto p)
{
    float costoPorProducto;
    costoPorProducto = p.Cantidad * p.PrecioUnitario;
    return costoPorProducto;
}