
#ifndef _USED_H_
#define _USED_H_

#include "auxb.h"
#include "search.h"
#include <math.h>

void delet(tree **root);

tree *comp(tree *root, int key);

void pagedad(tree *page, tree *root, tree **dad, int *posdad);

tree *pageX(tree *root, int key, bool *h, int *returnkey, D *pt);


#endif

