#include "Ventas.h"

#include <stdio.h>
#include "getsDatos.h"


static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i]==' '){
				continue;
			}
			if(cadena[i]=='-'){
				continue;
			}
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


static int esNumero(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}


int partida_setId(Partida* pVentas,int Aid){

	int ret=-1;
	if(pVentas!=NULL && Aid>0){
		pVentas->id=Aid;
		ret=0;
	}
	return ret;
}

int partida_setIdTxt(Partida* pVentas,char* Aid){

	int ret=-1;
	if(pVentas!=NULL && Aid!=NULL){
		if(esNumero(Aid, 10)){
			pVentas->id=atoi(Aid);
			ret=0;
		}
	}
	return ret;
}

int partida_setNombre(Partida* pVentas,char* nombre){
	int ret=-1;
	if(pVentas!=NULL && nombre!=NULL){
		printf(" en set nombre : nombre: %s  \n", nombre);

		//if(isValidNombre(nombre, LEN_STR)){
			strncpy(pVentas->nombre, nombre, LEN_STR);
			ret=0;
		//}
	}
		return ret;
}



int partida_setDia(Partida* pVentas,int dia){

	int ret=-1;
		if(pVentas!=NULL && dia>=0 && dia<=6){
			pVentas->dia=dia;
				ret=0;
		}
		return ret;
}



int partida_setTipoTxt(Partida* pVentas, char* Adia){

	int ret=-1;
	if(pVentas!=NULL && Adia!=NULL){

		if(esNumero(Adia, 3)){   //validar positivo
			pVentas->dia=atoi(Adia);
			ret=0;
		}
	}
		return ret;
}

int ventas_setHorario(Partida* pVentas,char* Ahorario){
	int ret=-1;
	if(pVentas!=NULL && Ahorario!=NULL){

			//validar
			strncpy(pVentas->horario, Ahorario, LEN_STR);
			ret=0;
	}
	return ret;
}

int partida_setSala(Partida* pVentas,int Asala){

	int ret=-1;
	if(pVentas!=NULL && Asala>=1 && Asala<=5){
		pVentas->sala=Asala;
		ret=0;
	}
	return ret;
}

int partida_setSalaTxt(Partida* pVentas,char* Asala){

	int ret=-1;
	if(pVentas!=NULL && Asala!=NULL){

		if(esNumero(Asala, 3)){
			pVentas->sala=atoi(Asala);
			ret=0;

		}
	}
	return ret;
}

int partida_setCantEntradas(Partida* pVentas,int AcantEntradas){

	int ret=-1;
	if(pVentas!=NULL && AcantEntradas>0){
		pVentas->cantEntradas=AcantEntradas;
		ret=0;
	}
	return ret;
}

int partida_setcantEntradasTxt(Partida* pVentas,char* AcantEntradas){

	int ret=-1;
	if(pVentas!=NULL && AcantEntradas!=NULL){

		if(esNumero(AcantEntradas, 3)){
			pVentas->sala=atoi(AcantEntradas);
			ret=0;
		}
	}
	return ret;
}


Partida* partida_new(){
	Partida* nuevaVenta=NULL;
	nuevaVenta=(Partida*)malloc(sizeof(Partida));
	return nuevaVenta;
}

Partida* partida_newParametros(int id, char* nombre, int dia, char* horario, int sala, int cantEntradas){
	Partida* pVentas=NULL;

	//mas validaciones
	if(id>0 && nombre!=NULL && dia>0 && horario!=NULL ){

		pVentas=partida_new();
		if(pVentas!=NULL){

			if(partida_setId(pVentas, id)==-1 ||
					partida_setNombre(pVentas, nombre)==-1 ||
					partida_setDia(pVentas, dia)==-1 ||
					ventas_setHorario(pVentas, horario)==-1 ||
					partida_setSala(pVentas, sala)==-1 ||
					partida_setCantEntradas(pVentas, cantEntradas)==-1){

						ventas_delete(pVentas);
						pVentas=NULL;
			}
		}
	}
	return pVentas;
}



Partida* partida_newParametrosTxt(char* id, char* nombre, char* dia, char* horario, char* sala, char* cantEntradas){

	Partida* pVentas=partida_new();



	if(id!=NULL && nombre!=NULL && dia!=NULL && horario!=NULL &&
			 sala!=NULL && cantEntradas!=NULL && pVentas!=NULL){




			//printf("%s \n", nombre);
			pVentas->id=atoi(id);
			strcpy(pVentas->nombre, nombre);
			pVentas->dia=atoi(dia);

			//partida_getNombre(pVentas, nombre);
			//printf("%s \n", pVentas->nombre);
//			strncpy(pVentas->horario, horario, LEN_STR);
//			pVentas->sala=sala;
	//		pVentas->cantEntradas=cantEntradas;


		/*	if(partida_setIdTxt(pVentas, id)==-1 ||
					//partida_setNombre(pVentas, nombre)==-1 ||
					partida_setTipoTxt(pVentas, dia)==-1 ||
					ventas_setHorario(pVentas, horario)==-1 ||
					partida_setSalaTxt(pVentas, sala)==-1 ||
					partida_setcantEntradasTxt(pVentas, cantEntradas)==-1){

					ventas_delete(pVentas);
				}*/


	}

	return pVentas;
}


int partida_print(Partida* pVentas){
	int ret=-1;
	int id;
	char nombre[128];
	int dia;
	char horario[6];
	int sala;
	int cantEntradas;

	if(pVentas!=NULL){
		partida_getId(pVentas, &id) ;
				partida_getNombre(pVentas, nombre);
				partida_getDia(pVentas, &dia);
				ventas_getHorario(pVentas, horario);

				partida_getSala(pVentas, &sala);
				partida_getCantEntradas(pVentas, &cantEntradas);


				printf("get en print %s", nombre);
			printf("Imprimo pventas: \nid: %d    nombre: %s  dia: %d   horario: %s   sala: %d    entradas: %d  \n",
			pVentas->id, pVentas->nombre, pVentas->dia, horario, sala, cantEntradas);



			ret=0;
		}

	return ret;
}


int partida_getId(Partida* pVentas,int* id){

	int ret=-1;
	if(pVentas!=NULL && id!=NULL){
		*id=pVentas->id;
		ret=0;
	}
	return ret;
}

int partida_getNombre(Partida* pVentas,char* nombre){
	int ret=-1;
		if(pVentas!=NULL && nombre!=NULL){
			strcpy(nombre, pVentas->nombre);
			printf(" get: %s  \n", nombre);
			ret=0;
		}

		return ret;
}


int partida_getDia(Partida* pVentas,int* dia){
	int ret=-1;
	if(pVentas!=NULL && dia!=NULL){
		*dia=pVentas->dia;
		ret=0;
	}
	return ret;
}

int getDiaStr(int ndia, char* dia){
	int ret=-1;
	if(ndia>=1 && ndia<=7 && dia!=NULL){
		ret=0;
		switch(ndia){
		case 0:
			strcpy(dia, "Domingo");
			break;
		case 1:
			strcpy(dia, "Lunes");
			break;
		case 2:
			strcpy(dia, "Martes");
			break;
		case 3:
			strcpy(dia, "Miercoles");
			break;
		case 4:
			strcpy(dia, "Jueves");
			break;
		case 5:
			strcpy(dia, "Viernes");
			break;
		case 6:
			strcpy(dia, "Sabado");
			break;
		}
	}
	return ret;
}


int ventas_getHorario(Partida* pVentas,char* horario){
	int ret=-1;
		if(pVentas!=NULL && horario!=NULL){
			strncpy(horario, pVentas->horario, LEN_STR);
			ret=0;
		}

		return ret;
}

int partida_getSala(Partida* pVentas,int* sala){
	int ret=-1;
	if(pVentas!=NULL && sala!=NULL){
		*sala=pVentas->sala;
		ret=0;
	}

	return ret;
}

int partida_getCantEntradas(Partida* pVentas,int* cantEntradas){
	int ret=-1;
	if(pVentas!=NULL && cantEntradas!=NULL){
		*cantEntradas=pVentas->cantEntradas;
		ret=0;
	}

	return ret;
}

int ventas_delete(Partida* pVentas){
	int ret=-1;
	if(pVentas!=NULL){
		free(pVentas);
		pVentas=NULL;
		ret=0;
	}
	return ret;
}

/*
int employee_setModificaciones(Ventas* this){
	int ret=-1;
	int option;
	char auxChar[LEN_STR];
	int auxInt;

	if(this!=NULL){

		if(addValoresAModificar(&option, auxChar, &auxInt)==0){

			switch(option){
			case 1:
				if(employee_setNombre(this, auxChar)==0){
					ret=0;
				}
				break;
			case 2:
				if(employee_setHorasTrabajadas(this, auxInt)==0){
					ret=0;
				}
				break;
			case 3:
				if(employee_setSueldo(this, auxInt)==0){
					ret=0;
				}
				break;
			}
		}
	}
	return ret;
}


int employee_criterioSueldo( void* item1, void* item2){
	int ret=0;

	Ventas* e1;
	Ventas* e2;

	int sueldo1;
	int sueldo2;
	int id1;
	int id2;

	if(item1!=NULL && item2!=NULL){

		e1=(Ventas*)item1;
		e2=(Ventas*)item2;

		if(employee_getSueldo(e1, &sueldo1)==0 && employee_getSueldo(e2, &sueldo2)==0){
			if(sueldo1>sueldo2){
				ret=1;
			}
			else if(sueldo2>sueldo1){
				ret=-1;
			}
			else{
				if(employee_getId(e1, &id1)==0 && employee_getId(e2, &id2)==0){
					if(id1>id2){
						ret=1;
					}
					else{
						ret=-1;
					}
				}
			}
		}

	}
	return ret;
}


int employee_criterioId( void* item1, void* item2){
	int ret=0;

	Ventas* e1;
	Ventas* e2;

	int id1;
	int id2;

	if(item1!=NULL && item2!=NULL){

		e1=(Ventas*)item1;
		e2=(Ventas*)item2;

		if(employee_getId(e1, &id1)==0 && employee_getId(e2, &id2)==0){
			if(id1>id2){
				ret=1;
			}
			else if(id2>id1){
				ret=-1;
			}

		}
	}

	return ret;
}


int employee_criterioNombre(void* item1, void* item2){
	int ret=0;
	Ventas* e1;
	Ventas* e2;

	char nombre1[LEN_STR];
	char nombre2[LEN_STR];
	int id1;
	int id2;

	if(item1!=NULL && item2!=NULL){

		e1=(Ventas*)item1;
		e2=(Ventas*)item2;

		if(employee_getNombre(e1, nombre1)==0 && employee_getNombre(e2, nombre2)==0){
				if(strcmp(nombre1, nombre2)>0){
					ret=1;
				}
				else if(strcmp(nombre1, nombre2)<0){
					ret=-1;
				}
				else{
					if(employee_getId(e1, &id1)==0 && employee_getId(e2, &id2)==0){
						if(id1>id2){
							ret=1;
						}
						else{
							ret=-1;
						}
					}
				}

		}
	}
	return ret;
}

int employee_criterioHoras( void* item1, void* item2){
	int ret=0;

	Ventas* e1;
	Ventas* e2;

	int horas1;
	int horas2;
	int id1;
	int id2;

	if(item1!=NULL && item2!=NULL){

		e1=(Ventas*)item1;
		e2=(Ventas*)item2;

		if(employee_getHorasTrabajadas(e1, &horas1)==0 && employee_getHorasTrabajadas(e2, &horas2)==0){
			if(horas1>horas2){
				ret=1;
			}
			else if(horas2>horas1){
				ret=-1;
			}
			else{
				if(employee_getId(e1, &id1)==0 && employee_getId(e2, &id2)==0){
					if(id1>id2){
						ret=1;
					}
					else{
						ret=-1;
					}
				}
			}
		}

	}
	return ret;
}


*/

void calculaMonto(void* pElement){

	int dia;
	int entradas;
	int monto;
	partida_getDia(pElement, &dia);
	partida_getCantEntradas(pElement, &entradas);
	if(dia==1 || dia==2 || dia==3){
		monto=240*entradas;
	}
	else{
		monto=350*entradas;
	}
	if(entradas>3){
		monto=0.9*monto;
	}



}



