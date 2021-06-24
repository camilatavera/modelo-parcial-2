#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArray)
{

	int ret=-1;
	char id[LEN_STR], nombre[LEN_STR], dia[LEN_STR], horario[LEN_STR], sala[LEN_STR], cantEntradas[LEN_STR];
	int flag=0; //lectura fantasma

	if(pFile!=NULL && pArray!=NULL){
		ret=0;


		do{

			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, dia,
					horario, sala, cantEntradas)==6 && flag){

				Partida* pVentas=NULL;
			//	printf("Lo q levanto en string \n id: %s    nombre: %s  dia: %s   horario: %s   sala: %s    entradas: %s  \n",
								//		id, nombre, dia, horario, sala, cantEntradas);


				pVentas=partida_newParametrosTxt(id, nombre, dia, horario, sala, cantEntradas);


				if(pVentas!=NULL){
					partida_print(pVentas);
					ll_add(pArray, pVentas);
				}
			}
				flag=1;



		}while(feof(pFile)==0);

	}

    return ret;
}


