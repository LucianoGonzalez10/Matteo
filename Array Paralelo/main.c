#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
const int dimC=100;
int cargarArrayParalelo(int dimension, char a[][dimC], int edad[], int legajo[]);
int searchPositionLegajo(int legajo[], int validos, int dato);
void searchName(int validos, char nombre[][dimC], int edad[], int legajo[]);
int main()
{
    int dimension=0, validos=0, i=0;
    printf("Dime la dimension de los arreglos paralelo\n");
    scanf("%i", &dimension);
    int edad[dimension];
    int legajo[dimension];
    char nombres[dimension][dimC];
    validos=cargarArrayParalelo(dimension, nombres, edad, legajo);
    while(i<validos){
        printf("Nombre:");
        puts(nombres[i]);
        printf("Edad:%i\n", edad[i]);
        printf("Legajo:%i\n", legajo[i]);
        i++;
    }
    i=0;
    i=searchPositionLegajo(legajo, validos, 54321);
    if(i==-1){
        printf("El dato no esta");
    }else{
        printf("El dato esta en la posicion %i", i);
    }
    searchName(validos, nombres, edad, legajo);
    return 0;
}
int cargarArrayParalelo(int dimension, char a[][dimC], int edad[], int legajo[]){
    char seguir='s';
    int i=0;
    for(i=0; i<dimension && (seguir=='s'||seguir=='S') ; i++){
        printf("Dime el nombre que quiere cargar\n");
        fflush(stdin);
        gets(a[i]);
        printf("Dime la edad\n");
        scanf("%i", &edad[i]);
        printf("Dime el legajo\n");
        scanf("%i", &legajo[i]);
        printf("Quiere seguir cargando datos s/n\n");
        fflush(stdin);
        scanf("%c", &seguir);
    }
    return i;
}
int searchPositionLegajo(int legajo[], int validos, int dato){
    int i=0, flag=0;
    while(i<validos && flag==0){
        if(legajo[i]==dato){
            flag=1;
        }else{
        i++;
        }
    }
    if(flag=0){
        i=-1;
    }
    return i;
}
void searchName(int validos, char nombre[][dimC], int edad[], int legajo[]){
    int dato=0;
    printf("\nDime el numero de legajo de la persona que quieres buscar\n");
    scanf("%i", &dato);
    int posicion=searchPositionLegajo(legajo, validos, dato);
    printf("\nEl nombre de la persona con el numero de legajo %i es ", legajo[posicion]);
    puts(nombre[posicion]);
}
void buscarMenorString ()
