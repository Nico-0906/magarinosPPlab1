#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "moto.h"
#include "servicio.h"
#include "trabajo.h"

void tipoNombre(char vec[], int tam){
    vec[0] = toupper(vec[0]);

    for(int i = 1 ; i < tam ; i++){
        vec[i] = tolower(vec[i]);
    }
}

void getStr(char cadena[], int tam){

    fgets(cadena, tam, stdin);

    for(int i = 0; i < tam; i++){
        if(cadena[i] == '\n'){
            cadena[i] = '\0';
        }
    }
}

char menuOpciones(){
    char retorno;
    int bandera = 0;
    system("clear");

    printf("****** Menu opciones ******\n\n");
    printf("A- Alta moto\n");
    printf("B- Modificar moto\n");
    printf("C- Baja moto\n");
    printf("D- Listar motos\n");
    printf("E- Listar tipos\n");
    printf("F- Listar colores\n");
    printf("G- Listar servicios\n");
    printf("H- Alta trabajo\n");
    printf("I- Listar trabajos\n");
    printf("J- Salir\n");
    fflush(stdin);

    while(bandera == 0){
        __fpurge(stdin);
        scanf("%c", &retorno);
        if( (retorno < 75 && retorno > 64) || (retorno < 107 && retorno > 96) ){
            bandera = 1;
        }else{
            printf("\nOpcion incorrecta, ingrese opcion: ");
        }
    }

    return retorno;
}

void getCharConfirmValidado(char* caracter){
    int bucle = 0;
    char opcion;

    while(bucle == 0){
        __fpurge(stdin);
        scanf("%c", &opcion);
        opcion = tolower(opcion);

        if(opcion == 's' || opcion == 'n' || opcion == 'S' || opcion == 'N'){
            *caracter = opcion;
            bucle = 1;
        }else{
            printf("\n Opcion incorrecta, ingrese S o N : ");
        }
    }
}
