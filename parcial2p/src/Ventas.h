/*
 * Ventas.h
 *
 *  Created on: Jun 23, 2021
 *      Author: caami
 */

#ifndef VENTAS_H_
#define VENTAS_H_
#define LEN_STR 128

typedef struct
{
    int id;
    char nombre[128];
    int dia;
    char horario[6];
    int sala;
	int cantEntradas;
}Partida;


#include "getsDatos.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


Partida* partida_new();
Partida* partida_newParametros(int id, char* nombre, int dia, char* horario, int sala, int cantEntradas);
Partida* partida_newParametrosTxt(char* id, char* nombre, char* dia, char* horario, char* sala, char* cantEntradas);

//int addValores(int *horas, int* sueldo, char *nombre);
int partida_setValores(Partida* pVentas, int id, int sueldo, int horas, char* nombre);

int partida_setId(Partida* pVentas,int Aid);
int partida_setIdTxt(Partida* pVentas,char* Aid);
int partida_getId(Partida* pVentas,int* id);

int partida_setNombre(Partida* pVentas,char* Anombre);
int partida_getNombre(Partida* pVentas,char* nombre);


int partida_setDia(Partida* pVentas,int Adia);
int partida_setTipoTxt(Partida* pVentas, char* Adia);
int partida_getDia(Partida* pVentas,int* dia);
int getDiaStr(int ndia, char* dia);

int ventas_setHorario(Partida* pVentas,char* Ahorario);
int ventas_getHorario(Partida* pVentas,char* horario);

int partida_setSala(Partida* pVentas,int Asala);
int partida_setSalaTxt(Partida* pVentas,char* sala);
int partida_getSala(Partida* pVentas,int* sala);

int partida_setCantEntradas(Partida* pVentas,int AcantEntradas);
int partida_setcantEntradasTxt(Partida* pVentas,char* AcantEntradas);
int partida_getCantEntradas(Partida* pVentas,int* cantEntradas);

int partida_print(Partida* pVentas);

void printModificaciones(void);




int ventas_delete(Partida* pVentas);
void calculaMonto(void* pElement);


/*
 * int addValoresAModificar(int *opcion, char *ingresoChar, int *ingresoInt);
int ventas_setModificaciones(Ventas* this);
int ventas_criterioSueldo( void* item1, void* item2);
int ventas_criterioId( void* item1, void* item2);
int ventas_criterioNombre(void* item1, void* item2);
int ventas_criterioHoras( void* item1, void* item2);

*/

#endif /* VENTAS_H_ */
