#ifndef _DEL_H_
#define _DEL_H_

#include "auxb.h"
#include "search.h"
#include "used.h"

bool is_leaf(tree *page);

tree *concatl(tree **dad, tree **page, tree **left, D *pt, int dadpos);

tree *concatr(tree **dad, tree **page, tree **right, D *pt, int dadpos);
/*tree *concatr(tree **dad, tree **page, tree **right, D *pt, int dadpos);*/

void organize_pont(tree **pont, int n);

tree *delete(tree *root, int key, D *pt);

tree *deleteprop(tree *dad, tree *page, int indad, int key, D *pt);

tree *prox(tree **pp, tree *p, tree *page, int inp, int inpp, D *pt);


#endif
