#include "used.h"

/*Destroi a arvore*/
void delet(tree **root)
{ 
	register int i;
	
	
   	i = 0;
		
		while(i < (*root)->qtd_ch + 1) 
		{
   		if((*root)->son[i] != NULL)
			{
           	(*root)->son[i] = NULL;
				free((*root)->son[i]);
			}
		i++;
		}
	*root = NULL;
		
}

/*pagedad identifica o pai de uma pagina, passando uma pagina qualquer da arvore 
a funcao retorna o pai desta pagina e a posicao na pagina pai.*/
void pagedad(tree *page, tree *root, tree **dad, int *posdad)
{

	int i, j;
	if(root != NULL)
	{
		printf("Ola bom dia estou procurando o pai do no page %d. \n", page->ch[0]);
		for(i = 0; i <= root->qtd_ch ; i++)
		{	
			
			pagedad( page,root->son[i], dad, posdad);
			if(root->son[i] != NULL)
			{
				for(j = 0; j <= root->qtd_ch; j++)
				{
					if(root->son[i] == page)
					{
						printf("pai eh a page %d no filho %d\n", root->ch[i], i);
						*posdad = i;
						*dad = root;
					}
				}
			}
			
		}
		pagedad(page,root->son[i], dad, posdad);
	}

}

/*Funcao de busca auxiliar
retorna a pagina em que esta uma determinada chave
*/
tree *pageX(tree *root, int key, bool *h, int *returnkey, D *pt)
{
	int pos;
	tree *page;
	
	if(root != NULL)
	{
		pos =  binarysearch( root, key);
		*returnkey = pos;
		if(root->qtd_ch > pos && root->ch[pos] == key)
		{
			*h = false;
		}
		else
		{
			/*desce ate encontar a pagina em que esta chave*/
			page =  pageX(root->son[pos], key, h, returnkey, pt);
			return page;
			if(*h)/*pagina encontrada*/
			{
				*h = false;
				return root ;
			}
		
		}
		return root;
	}
	return root;
}

/**funcao que percorre toda a arvore em busca de uma chave key*/
tree *comp(tree *root, int key)
{
	int i, pos;
	tree *aux;
	aux = (tree *) malloc (sizeof(tree));
	if(root != NULL)
	{
		i = 0;
		pos =  binarysearch( root, key);
		while(i < root->qtd_ch)
		{
			if(root->qtd_ch > pos && root->ch[pos] == key)
			{
				aux = root;
				return aux;
			}
			i++;
		}
		for(i  = 0; i <= root->qtd_ch; i++)
		{
			return comp(root->son[i], key);
		}
	}
	return aux;
	free(aux);

}

