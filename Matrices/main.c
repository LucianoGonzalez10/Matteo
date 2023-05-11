#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
const int dimC=100;
int matrizString (char a[][dimC], int dimF);
void mostrarString (char a[][dimC], int f);
int encontrarString (char a[][dimC], char palabra[], int f);
int encontrarStringAlfa (char a[][dimC], char palabra[], int f);
void ordenarUnStrings(char a[][dimC], int val);
void ordenarStringEntero (char a[][dimC], int val);
int main()
{
    int dimF=0, i=0, res=0, posicion=0;
    printf("Dime la cantidad de palabras");
    scanf("%i", &dimF);
    char palabra[dimF][dimC];
    char palabra2[] ={"auto"};
    i=matrizString(palabra, dimF);
    mostrarString(palabra, i);

    res=encontrarString(palabra, palabra2, i);
    if(res!=-1){
        printf("La palabra se encuentra en la posicion %i", res);
    }else{
        printf("La palabra no esta");
    }
    res=encontrarStringAlfa(palabra, palabra2, i);
    if(res!=-1){
        printf("\nLa palabra se encuentra en la posicion %i", res);
    }else{
        printf("\nLa palabra no esta\n");
    }
    ordenarStringEntero(palabra, i);
    mostrarString(palabra, i);
    return 0;
}
///Actividad 7
int matrizString (char a[][dimC], int dimF){
    int f=0;
    char control='s';
    for(f=0; f<dimF && (control=='s' || control=='S'); f++){
        printf("\nIngrese una palabra para cargar en la matriz\n");
        fflush(stdin);
        gets(a[f]);
        printf("\nQuieres seguir cargando palabras s/n\n");
        fflush(stdin);
        scanf("%c", &control);
    }
    return f;
}
///Actividad 8
void mostrarString (char a[][dimC], int f){
    for(int i=0; i<f; i++){
    puts(a[i]);
    }
}
///Actividad 9
int encontrarString (char a[][dimC], char palabra[], int f){
    int res=-1;

    for(int i=0; i<f && res == -1; i++){
        if(strcmp(a[i], palabra)==0)
        {
            res=i;
        }
    }
    return res;
}
///Actividad 10
int encontrarStringAlfa (char a[][dimC], char palabra[], int f){
    int res=-1;
    for(int i=0; i<f && res == -1 && (strcmp(a[i], palabra) <= 0); i++){
        if(strcmp(a[i], palabra)==0)
        {
            res=i;
        }
    }
    return res;
}
///Actividad 11
void ordenarUnStrings(char a[][dimC], int val){
    char mayor[val][dimC];
    int i=val-2;
    while(i>=0){
        if(strcmpi(a[i], a[i+1]) > 0){
            strcpy(mayor[i], a[i]);
            strcpy(a[i], a[i+1]);
            strcpy(a[i+1], mayor[i]);
        }
        i--;
    }
}
void ordenarStringEntero (char a[][dimC], int val){
    int i=0;
    while(i<val){
        ordenarUnStrings(a, i);
        i++;
    }
}
