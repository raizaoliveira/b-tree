#include "del.h"

bool is_leaf(tree *page)
{
	register int i;
	bool h;
	h = true;
	i = 0;
	while(i <= page->qtd_ch && h)
	{
		if(page->son[i] != NULL)
		{
			h = false;
		}
		i++;
	}
	
	return h;

}

void organize_pont(tree **pont, int n)
{
	register int i;
	for(i = n; i > 0; i--)
	{
		(*pont)->son[i] = (*pont)->son[i- 1];
	}


}

tree *concatr(tree **dad, tree **page, tree **right, D *pt, int dadpos)
 {
	int *array;
	int n, m, lenght, middle;
	int test = 0;
	register int i, k;

	n =  (4 * (pt->d)) + 2;
	array = (int *) calloc( n + 1, sizeof(int));

	for(i = 0; i < (*right)->qtd_ch; i++)
	{
		array[i] = (*right)->ch[i];
	}
	
	m = i;
	array[m] = (*dad)->ch[dadpos - 1];
	i++;
	for(k = 0; k < (*page)->qtd_ch; k++)
	{
		array[i] = (*page)->ch[k];
		i++;
	}
	lenght = i;
	if(lenght <= pt->m)
	{/*a pagina fica menor que 2d entao retorna uma unica pagina*/
		(*right)->qtd_ch = lenght;
		for(i = 0; i < lenght; i++)
		{
			(*right)->ch[i] = array[i];
			(*right)->son[i] = NULL;
		}

		(*dad)->qtd_ch--;
		(*dad)->son[dadpos] = NULL;
		return (*dad);
	}
	else
	{
		middle = (lenght / 2);

		/*invertendo para reorganizar*/
		(*dad)->ch[dadpos - 1] = array[middle];
		(*right)->qtd_ch = middle;
		for(i = 0; i < (*right)->qtd_ch; i++)
		{
			(*right)->ch[i] = array[i] ;
		}
		m = lenght - i;
		i = middle + 1;
	   (*page)->qtd_ch = i - 1;
		for(k = m; k < lenght; k++)
		{
			(*page)->ch[test] = array[k] ;
			test++;
		}
		
		(*dad)->son[dadpos] = *page;
		(*dad)->son[dadpos - 1] = *right;
		return  (*dad);
	}
	return (*dad);
	
	
}


tree *concatl(tree **dad, tree **page, tree **left, D *pt, int dadpos)
 {
	int *array;
	int n, m, lenght, middle;
	int test = 0;
	register int i, k;

	n =  (4 * (pt->d)) + 2;
	array = (int *) calloc( n + 1, sizeof(int));
	
	for(i = 0; i < (*page)->qtd_ch; i++)
	{
		array[i] = (*page)->ch[i];
	}
	
	m = i;
	array[m] = (*dad)->ch[dadpos];
	i = ++m;

	for(k = 0; k < (*left)->qtd_ch; k++)
	{
		array[i] = (*left)->ch[k];
		i++;
	}
	lenght = i;
	
	if(lenght <= pt->m)
	{/*a pagina fica menor que 2d entao retorna uma unica pagina*/
		for(i = 0; i < lenght; i++)
		{
			(*page)->ch[i] = array[i];
			(*page)->son[i] = NULL;
		}
		(*page)->qtd_ch = lenght;
		(*dad)->son[dadpos + 1] = NULL;
		(*dad)->qtd_ch--;
		
		free(*left);
		(*dad)->son[dadpos] = (*page);
		return (*dad);
	}
	else
	{/*SE a juncao das duas paginas for maior que 2d entao deve redistribuir as chaves*/
		middle = ((lenght ) / 2);/*mediana do conjunto na posicao middle*/
		/*invertendo para reorganizar*/
		(*dad)->ch[dadpos] = array[middle];

		for(i = 0; i < middle; i++)
		{
			(*page)->ch[i] = array[i] ;
		}
		(*page)->qtd_ch = i;
		i = middle + 1;
		m = lenght - i;
		for(k = i; k < lenght; k++)
		{
			(*left)->ch[test] = array[k] ;
			test++;
		}
		/*reorganiza os ponteiros e retorna o pai*/
		(*left)->qtd_ch = m;
		(*dad)->son[dadpos] = *page;
		(*dad)->son[dadpos + 1] = *left;
		return  (*dad);
	}
	return (*dad);
	
	
}

/*Busca a chave seguinte a uma chave a ser deletada em uma pagian nao folha*/
tree *prox(tree **pp, tree *p, tree *page, int inp, int inpp, D *pt)
{
	register int i;
	
	if(is_leaf(page))
	{
		(*pp)->ch[inpp] = page->ch[0];
		for(i = 0; i <= page->qtd_ch; i++)
		{
			page->ch[i] = page->ch[i+1];
		}
		page->qtd_ch -= 1;
	}
	else
   {
		page = prox(&(*pp), page, page->son[0], 0, inpp, pt);
	}

	if(page->qtd_ch < pt->d)
	{
		if(p->son[inp + 1] != NULL)
		{
			p = concatl( &p, &page, &(p->son[inp + 1]), pt, inp);
		}
		else
		{
			p = concatr(&p, &page, &(p->son[inp - 1]), pt, inp);
		}


	}

	return p;
}



/*propagacao na arvore*/
tree *deleteprop(tree *dad, tree *page, int indad, int key, D *pt)
{
	int index;
	register int i;
	if(page != NULL)
	{
		index = binarysearch(page, key);

		if(page->ch[index] == key)
		{
			if(is_leaf(page))/*se a pagina for folha simplesmente deleta-se a chave*/
			{
				for(i = index; i < page->qtd_ch; i++)
				{
					page->ch[i] = page->ch[i+1];
				}
				page->qtd_ch -= 1;
			}
			else/*Senao encontra um substituto para a chave a ser deletada*/
			{
				page = prox(&page, page, page->son[index+1], index + 1, index, pt);
			}
		}
		else
		{/*senao houver sucessor entao tem-se o anterior*/
			page = deleteprop( page, page->son[index], index, key, pt);
		}

	
		if(page->qtd_ch < pt->d)
		{
			if(dad->son[indad + 1] != NULL)
			{/*concatenacao a esquerda*/
				dad = concatl( &dad, &page, &(dad->son[indad + 1]), pt, indad);
			}
			else 
			{/*concatenacao a direita*/
				dad = concatr( &dad, &page, &(dad->son[indad - 1]), pt, indad);
			}
		}
	}
	else
	{
		printf("Chave nao existe\a\n");
	}



	return dad;

}

/*caso especial para raiz*/
tree *delete(tree *root, int key, D *pt)
{
	int index;
	register int i;
   tree *aux;
	bool h;
	int re;
	if(root != NULL)
	{
		aux = pageX(root, key, &h, &re, pt);
		if (aux!= NULL)
		{
			index = binarysearch(root, key);

			if(root->ch[index] == key)
			{
				if(is_leaf(root))
				{
					for(i = index; i < root->qtd_ch; i++)
					{
						root->ch[i] = root->ch[i+1];
					}
					root->qtd_ch -= 1;
				}
				else
				{
					root = prox(&root, root, root->son[index+1], index+1, index, pt);
				}
			}
			else
			{
				root = deleteprop(root, root->son[index], index, key, pt);
			}
		}
		else 	puts("chave nao existe");

	}
	else
	{
		printf("Chave nao existe \a\n");
	}



	return root;

}



