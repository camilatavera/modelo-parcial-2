/*
 * getsDatos.h
 *
 *  Created on: Apr 28, 2021
 *      Author: caami
 */

#ifndef GETSDATOS_H_
#define GETSDATOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>


int getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo,
		int reintentos);

int getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo,
		int maximo, int reintentos);

int getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo,
		int reintentos);


int validarChar(char* pResultado, char* mensaje, char* mensajeError, char opcion1,
				char opcion2, int reintentos);

int utn_getString(char *pResultado, int len, char* mensaje, char* mensajeError, int reintentos);

int getInt(int *pResultado);

int limpiarArrayChar(char array[],int leng);

int esNumerica(char string[], int leng);
int esUnaPalabra(char string[], int leng);
int sonPalabras(char string[], int leng);



#endif /* GETSDATOS_H_ */
