

#include "auxb.h"

/*inicia os valores dos parametros da arvore

le-se a ordem, calcula-se  os valores e guarda os e uma estrutura*/
void init_tree(D *pt)
{
	
	do{
		printf("Informe a ordem da arvore:  ");
		scanf(" %d", &(pt->d));
	}while(pt->d > 50);

	pt->m = (2 * (pt->d) ) ;/*numero maximo de chaves por pagina, sendo a pagina diferente da raiz ou folha*/
	pt->minson = pt->d + 1;/*cada pagina diferente da raiz ou folha contem no minimo d+1 filhos*/

	pt->maxson = (2 * (pt->d)) + 1;/*numero maximo de filhos*/
	pt->minoc = pt->d;


}


