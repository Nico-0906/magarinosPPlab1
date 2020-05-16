#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
    int isEmpty;

}eTipo;


#endif // TIPO_H_INCLUDED


int cargarTipo(char descripcion[], int id, eTipo tipos[], int tamtip);
void inicializarTipo(eTipo tipos[], int tamtip);
void mostrarTipos(eTipo tipos[], int tamtip);
