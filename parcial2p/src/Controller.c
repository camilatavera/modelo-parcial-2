/*
 * Controller.c
 *
 *  Created on: Jun 23, 2021
 *      Author: caami
 */

#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"




/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArray)
{
	int ret=-1;
	FILE* fp=NULL;

	if(path!=NULL && pArray!=NULL ){

		fp=fopen(path, "r");

		if(fp!=NULL){
			parser_EmployeeFromText(fp, pArray);
			fclose(fp);
			ret=0;
		}
	}
    return  ret;;
}


int controller_ListVentas(LinkedList* pArray)
{
	int ret=-1;
	Partida* pVentas;
	int i;

	int id;
	char nombre[LEN_STR];
	int ndia;
	char dia[8];
	char horario[8];
	int sala;
	int cantEntradas;

	if(pArray!=NULL){

		if(ll_len(pArray)==0){
			printf("No hay empleados ingresados al sistema \n");
		}
		else{
			ret=0;
			printf("Id    Nombre               Dia      Horario  Sala    Cant Entradas \n");

			for(i=0; i<ll_len(pArray); i++){
				pVentas=ll_get(pArray, i);

				if(partida_getId(pVentas, &id)==0 && partida_getNombre(pVentas, nombre)==0 && partida_getDia(pVentas, &ndia)==0 &&
						getDiaStr(ndia, dia)==0 && ventas_getHorario(pVentas, horario)==0 &&
						partida_getSala(pVentas, &sala)==0 && partida_getCantEntradas(pVentas, &cantEntradas)==0){


					printf("%-5d %-8s %-8s %-8s %-8d %d  \n", id, nombre, dia, horario, sala, cantEntradas);
				}

			}//cierro for


		}
	}
	return ret;

}

int controller_saveAsText(char* path , LinkedList* pArray){
	int ret=-1;
	FILE* fp;
	Partida* pVentas;
	int i;
	int len;

	int id;
	char nombre[LEN_STR];
	int dia;
	char horario[6];
	int sala;
	int cantEntradas;

	int cont=0;

	if(path!=NULL && pArray!=NULL){
		len=ll_len(pArray);

		if(len==0){
			printf("No hay datos cargados para guardar \n");
		}
		else{
			fp=fopen(path, "w");

			if(fp!=NULL){

				fprintf(fp, "id_venta,nombre_pelicula,dia,horario,sala,cantidad_entradas,montos\n");

				ll_map(pArray, calculaMonto);
				for(i=0; i<len; i++){
					pVentas=ll_get(pArray, i);

					if(partida_getId(pVentas, &id)==0 && partida_getNombre(pVentas, nombre)==0 &&
							partida_getDia(pVentas, &dia)==0 && ventas_getHorario(pVentas, horario)==0 &&
							partida_getSala(pVentas, &sala)==0 && partida_getCantEntradas(pVentas, &cantEntradas)==0){

						//falta montos
						printf("%-5d %-8s %-8d %-8s %-8d %d  \n", id, nombre, dia, horario, sala, cantEntradas);
						cont++;
					}

				}//cierro for
				fclose(fp);

				if(cont==len){
					ret=0;
				}
			}
		}//cierro else
	}//ciero validacion
    return ret;
}
