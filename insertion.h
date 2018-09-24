#ifndef _INSERTION_H_
#define _INSERTION_H_

#include "auxb.h"
#include "interface.h"
#include "used.h"
#include "search.h"

/*Insere uma chave e o ponteiro para  o filho da direita de um no*/
void insertKey(tree *root, int key, tree *noright);

tree *split(tree *root, tree *right_son, int *back, D *pt);

/*realiza a busca do no para inserir a chave e faz as subdivisoes quando necessario*/
tree *insert(tree *root, int key, bool *h, int *returnkey, D *pt);

tree *insertB(tree *root, int key, D *pt);

void emordem(tree *raiz);

#endif

