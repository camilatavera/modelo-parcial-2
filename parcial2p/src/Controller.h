/*
 * Controller.h
 *
 *  Created on: Jun 23, 2021
 *      Author: caami
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#include "LinkedList.h"

#include "parser.h"
#include "Ventas.h"


int controller_loadFromText(char* path , LinkedList* pArray);

int controller_ListVentas(LinkedList* pArray);
int controller_saveAsText(char* path , LinkedList* pArray);



#endif /* CONTROLLER_H_ */
