#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id;
    char nombreColor[20];
    int isEmpty;

}eColor;


#endif // COLOR_H_INCLUDED

/**
*
*
*
*/
int cargarColor(char descripcion[], int id, eColor colores[], int tamcol);
int cargarTipo(char descripcion[], int id, eTipo tipos[], int tamtip);
void inicializarColores(eColor colores[], int tamcol);
void mostrarColores(eColor colores[], int tamcol);
