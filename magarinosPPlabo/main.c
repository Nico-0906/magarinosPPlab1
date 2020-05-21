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
#include "herramientas.h"

#define TAMMOT 3
#define TAMTIP 4
#define TAMCOL 5
#define TAMSER 4
#define TAMTRA 3
#define TAMFEC 5


int main()
{
    char salir = 'n';
    int autoIdMoto = 0;
    int autoIdTrabajo = 0;
    int gatillo = 0;
    int gatilloTrabajo = 0;

    eMoto motos[TAMMOT]; //= {{0, "jawa", 1000, 10000, 750, 0}, {1, "kawa", 1001, 10002, 600, 0}, {2, "suzu", 1002, 10003, 50, 0}};
    eTipo tipos[TAMTIP] = {{1000, "Enduro"}, {1001, "Chopera"}, {1002, "Scooter"}, {1003, "Ciclomotor"}};
    eColor colores[TAMCOL] = {{10000, "Gris"}, {10001, "Negro"}, {10002, "Blanco"}, {10003, "Azul"}, {10004, "Rojo"}};
    eServicio servicios[TAMSER] = {{20000, "Limpieza", 250.00}, {20001, "Ajuste", 300.00}, {20002, "Balanceo", 17.00}, {20003, "Cadena", 190.50}};
    eTrabajo trabajos[TAMTRA]; //= {{0, 0, 20002, {25, 4, 2020}, 0}};

    inicializarMoto(motos, TAMMOT);
    //inicializarTipo(tipos, TAMTIP);
    //inicializarColores(colores, TAMCOL);
    //inicializarServicios(servicios, TAMSER);
    inicializarTrabajos(trabajos, TAMTRA);

    do{
        switch(menuOpciones()){
            case 'a':
                if(altaMoto(autoIdMoto, motos, TAMMOT, tipos, TAMTIP, colores, TAMCOL)){
                    autoIdMoto++;
                    gatillo++;
                }
                break;
            case 'b':
                if(gatillo > 0){
                    modificarMoto(motos, TAMMOT, tipos, TAMTIP, colores, TAMCOL);
                }else{
                    printf("\nPrimero debe dar de alta una moto. \n");
                    __fpurge(stdin);
                    getchar();
                }
                break;
            case 'c':
                if(gatillo > 0){
                    if(bajaMoto(motos, TAMMOT, tipos, TAMTIP, colores, TAMCOL)){
                        gatillo--;
                    }
                }else{
                    printf("\nPrimero debe dar de alta una moto. \n");
                    __fpurge(stdin);
                    getchar();
                }
                break;
            case 'd':
                if(gatillo > 0){
                    system("clear");
                    listarMotos(motos, TAMMOT, tipos, TAMTIP, colores, TAMCOL);
                    __fpurge(stdin);
                    getchar();
                }else{
                    printf("\nPrimero debe dar de alta una moto. \n");
                    __fpurge(stdin);
                    getchar();
                }
                break;
            case 'e':
                mostrarTipos(tipos, TAMTIP);
                __fpurge(stdin);
                getchar();
                break;
            case 'f':
                mostrarColores(colores, TAMCOL);
                __fpurge(stdin);
                getchar();
                break;
            case 'g':
                system("clear");
                mostrarServicios(servicios,  TAMSER);
                __fpurge(stdin);
                getchar();
                break;
            case 'h':
                if(gatillo > 0){
                    if(altaTrabajos(autoIdTrabajo, motos, TAMMOT, colores, TAMCOL, servicios, TAMSER, tipos, TAMTIP, trabajos, TAMTRA)){
                        autoIdTrabajo++;
                        gatilloTrabajo++;
                    }
                }else{
                    printf("\nPrimero debe dar de alta una moto. \n");
                    __fpurge(stdin);
                    getchar();
                }
                break;
            case 'i':
                if(gatilloTrabajo > 0){
                    system("clear");
                    listarTrabajos(trabajos, TAMTRA, motos, TAMMOT, servicios, TAMSER);
                }else{
                    printf("\nPrimero debe dar de alta Trabajos \n");
                    __fpurge(stdin);
                    getchar();
                }
                break;
            case 'j':
                printf("\nConfirma salida? s/n \n");
                getCharConfirmValidado(&salir);
                break;
        }

    }while(salir == 'n');

    return 0;
}
