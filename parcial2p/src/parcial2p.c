/*
 ============================================================================
 Name        : parcial2p.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "menu.h"

int main(void) {

	setbuf(stdout, NULL);

	    int option;
//	 char nombreArchivo[128];


	    LinkedList* listaVentas = ll_newLinkedList();



	    do{
	    	printMenu();
	    	getNumero(&option, "Ingrese opcion de menu\n", "Error. ", 1, 6, 25);


	        switch(option)
	        {
	            case 1:
	            //	utn_getString(nombreArchivo, 123,
	            //	"Ingrese el nombre del archivo (hola.csv) \n", "Error. ", 25);


	                if(controller_loadFromText("hola.csv", listaVentas)==0){
	                	printf("Operacion realizada con exito \n");
	                }
	                break;

	            case 2:
	            	controller_ListVentas(listaVentas);
	            	break;

	            case 3:
	            	controller_saveAsText("monto.csv", listaVentas);
	            	break;



	        }
	    }while(option!=6);
	    return 0;
}

