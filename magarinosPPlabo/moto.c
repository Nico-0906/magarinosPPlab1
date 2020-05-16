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


int mostrarMoto(eMoto motos , int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol){
    char color[20];
    char tipo[20];

    cargarColor(color , motos.idColor, colores, tamcol);
    cargarTipo(tipo , motos.idTipo, tipos, tamtip);

    printf("%d    %10s    %10s     %10s     %4d\n", motos.id , motos.marca , tipo, color, motos.cilindrada);

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

    printf("Ingrese ID de moto: \n");
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
    printf("****** MOTOS ******\n\n");
    printf("ID    MARCA     TIPO     COLOR      CILINDRADA\n\n");

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
    getStr(auxMoto.marca, 20);
    fflush(stdin);
    getchar();

    mostrarTipos(tipos, tamtip);
    printf("\nIngrese tipo por id: \n");
    fflush(stdin);
    scanf("%d", &auxMoto.idTipo);
    getchar();

    mostrarColores(colores, tamcol);
    printf("Ingrese color por id: \n");
    scanf("%d", &auxMoto.idColor);
    fflush(stdin);
    getchar();

    printf("Ingrese cilindrada: \n");
    scanf("%d", &auxMoto.cilindrada);
    fflush(stdin);
    getchar();

    printf("\nMoto agregada con exito.!");

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
