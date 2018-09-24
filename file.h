/*Biblioteca com funcoes para manipulacao 
de arvores B em arquivo binario*/

#ifndef _FILE_H_
#define _FILE_H_

#include "auxb.h"


void savefile(tree **root, FILE *p);

tree *openfile(FILE *p);


#endif
