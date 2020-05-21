#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id;
    int idMoto;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED

int cargarMoto(char nombreMarca[], int id, eMoto motos[], int tammot);

int cargarServicio(char nombreServicio[], int id, eServicio servicios[], int tamser);

void mostrarTrabajo(eTrabajo trabajos, eMoto motos[], int tammot, eServicio servicios[], int tamser);

void listarTrabajos(eTrabajo trabajos[], int tamtra, eMoto motos[], int tammot, eServicio servicios[], int tamser);

int buscarLibreTrabajo(eTrabajo trabajos[], int tamtra);

int altaTrabajos(int id, eMoto motos[], int tammot, eColor colores[], int tamcol, eServicio servicios[], int tamser, eTipo tipos [], int tamtip, eTrabajo trabajos[], int tamtra);

void inicializarTrabajos(eTrabajo trabajos[],int tamtra);
