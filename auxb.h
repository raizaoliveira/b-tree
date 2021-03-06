
#ifndef _AUXB_H_
#define _AUXB_H_

/*A ordem maxima permitida eh 50*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
#define max 100
#define min_occ_root 2;
typedef int bool;


typedef struct no tree;
struct no
{
	int qtd_ch;
	int ch[max];
	tree *son[max + 1];
};

typedef struct  ordem 
{
	int d;/*ordem da arvore*/
	int m;/*numero de chaves. Deve estar entre d e 2d. Obs raiz possui entre 1 e 2d chaves*/
	int minson;/*numero minimo de filhos d + 1, exceto raiz e folhas*/
	int maxson;/*cada no tem no maximo 2d + 1 filhos */
	int minoc; /*ocupacao minima de cada no*/
}D;

void init_tree(D *pt);

#endif
