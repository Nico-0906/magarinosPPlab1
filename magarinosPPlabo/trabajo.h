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


int altaTrabajos();

void mostrarTrabajos(eTrabajo trabajos[], int tamtra);

void inicializarTrabajos(eTrabajo trabajos[],int tamtra);
