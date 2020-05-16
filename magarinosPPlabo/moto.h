#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED

typedef struct{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int cilindrada;
    int isEmpty;

}eMoto;

#endif // MOTO_H_INCLUDED

void bajaMoto(eMoto motos[] , int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol);

void mostrarMoto(eMoto motos , int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol);

void listarMotos(eMoto motos[], int tammot, eTipo tipos[], int tamtip, eColor colores[], int tamcol);

int altaMoto();

int buscarLibreMoto(eMoto motos[], int tammot);

void inicializarMoto(eMoto motos[], int tammot);
