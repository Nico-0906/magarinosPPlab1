#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[25];
    float precio;
    int isEmpty;

}eServicio;

#endif // SERVICIO_H_INCLUDED

void mostrarServicios(eServicio servicios[], int tamser);

void inicializarServicios(eServicio servicios[], int tamser);
