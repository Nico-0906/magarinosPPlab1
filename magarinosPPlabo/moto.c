#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "moto.h"
#include "servicio.h"
#include "trabajo.h"
#include "herramientas.h"

void modificarMoto(eMoto motos[], int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol){
    system("cls");
    int auxId;
    int busqueda;
    char confirmacion;
    eMoto auxMoto;

    printf("***** MODIFICAR MOTO ***** \n\n");

    listarMotos(motos, tammot, tipos, tamtip, colores, tamcol);
    printf("\nIngrese ID de MOTO: ");
    fflush(stdin);
    scanf("%d", &auxId);
    getchar();

    busqueda = buscarMoto(auxId, motos, tammot);

    if(busqueda != -1){
        mostrarMoto(motos[busqueda] , tammot, tipos, tamtip, colores, tamcol));

        printf("Que desea modificar: \n\n1- Color\n 2- Cilindrada\n 3- Cancelar \n\n");


        scanf("%d", &opcion);

    switch(opcion){
        case 1:
            printf("Seleccione nuevo color: \n");
            mostrarColores(colores, tamcol);
            fflush(stdin);
            scanf("%d", &auxMoto.idColor);

            printf("\nDesea confirmar la modificacion? s/n \n\n");
            fflush(stdin);
            scanf("%c", &confirmacion);

            if(confirmacion == 's'){
                motos[busqueda].idColor = auxMoto.idColor;
                printf("\nModificado con exito.! \n\n");
            }else{
                printf("\nOperacion cancelada. \n\n");
            }
            break;
        case 2:
            printf("Ingrese nueva cilindrada: \n");
            scanf("%d", &auxMoto.cilindrada);
            printf("\nDesea confirmar la modificacion? s/n \n\n");
            fflush(stdin);
            scanf("%c", &confirmacion);

            if(confirmacion == 's'){
                motos[busqueda].cilindrada = auxMoto.cilindrada;
                printf("\nModificado con exito.! \n\n");
            }else{
                printf("\nOperacion cancelada. \n\n");
            }
            break;
        case 3:
           break;
    }

    }else{
        printf("\nMoto no encontrada. \n\n");
    }
}

void mostrarMoto(eMoto motos , int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol){
    char color[20];
    char tipo[20];

    cargarColor(color , motos.idColor, colores, tamcol);
    cargarTipo(tipo , motos.idTipo, tipos, tamtip);

    printf("%d    %10s    %10s    %10s       %4d\n", motos.id , motos.marca , tipo, color, motos.cilindrada);
}

int buscarMoto(int id, eMoto motos[], int tammot){
    int retorno = -1;
    for(int i = 0 ; i < tammot ; i++){
        if(motos[i].id == id && motos[i].isEmpty == 0){
            retorno = i;
            break;
        }
    }

    return retorno;
}

void bajaMoto(eMoto motos[] , int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol){

    system("cls");

    int auxId;
    int busqueda;
    char confirmacion;

    printf("***** BAJA MOTO ***** \n\n");

    listarMotos(motos, tammot, tipos, tamtip, colores, tamcol);
    printf("\nIngrese ID de moto: \n");
    scanf("%d", &auxId);

    busqueda = buscarMoto(auxId, motos, tammot);

    if(busqueda != -1){
        //mostrarMoto(motos, tammot, tipos, tamtip, colores, tamcol);

        printf("\nDesea confirmar la baja? s/n \n\n");
        fflush(stdin);
        scanf("%c", &confirmacion);

        if(confirmacion == 's'){
            motos[busqueda].isEmpty = 1;
            printf("\nDada de baja con exito.! \n\n");
        }else{
            printf("\nOperacion cancelada. \n\n");
        }
    }else{
        printf("\nMoto no encontrada. \n\n");
    }
}

void listarMotos(eMoto motos[] , int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol){
    system("cls");
    printf("****** MOTOS ******\n\n");
    printf("ID         MARCA        TIPO          COLOR     CILINDRADA\n\n");

    for(int i = 0 ; i < tammot ; i++){
        if(motos[i].isEmpty == 0){
            mostrarMoto(motos[i] , tammot, tipos, tamtip, colores, tamcol);
        }
    }
    fflush(stdin);
    getchar();
}

int buscarLibreMoto(eMoto motos[], int tammot){
    int posicion = -1;
        for(int i = 0 ; i < tammot ; i++){
            if(motos[i].isEmpty == 1){
                posicion = i;
                break;
            }
        }
    return posicion;
}

int altaMoto(int idMoto, eMoto motos[], int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol){
    int retorno = 0;
    int lugar;

    system("cls");

    printf("****** ALTA MOTO ******\n\n");

    eMoto auxMoto;

    lugar = buscarLibreMoto(motos, tammot);

    if(lugar == -1){

    printf("\nNo hay lugar para mas motos. \n\n");

    }else{

    auxMoto.id = idMoto;

    printf("Ingrese marca: \n");
    fflush(stdin);
    getStr(auxMoto.marca, 20);
    getchar();

    mostrarTipos(tipos, tamtip);
    printf("\nIngrese tipo por id: \n");
    fflush(stdin);
    scanf("%d", &auxMoto.idTipo);

    mostrarColores(colores, tamcol);
    printf("Ingrese color por id: \n");
    scanf("%d", &auxMoto.idColor);

    system("cls");
    printf("Ingrese cilindrada: \n");
    scanf("%d", &auxMoto.cilindrada);

    printf("\nMoto agregada con exito.!");

    fflush(stdin);
    getchar();

    auxMoto.isEmpty = 0;

    motos[lugar] = auxMoto;

    retorno = 1;
    }

    return retorno;
}

void inicializarMoto(eMoto motos[], int tammot){
     for(int i = 0 ; i < tammot ; i++){
        motos[i].isEmpty = 1;
     }
}
