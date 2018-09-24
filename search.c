
#include "search.h"

/*busca binaria.
recebe a raiz da arvore . 
percorre as paginas e os filhos em busca da chave procurada*/
int binarysearch(tree *root, int key)
{
	int half, i , last;
	i = 0;
	last = root->qtd_ch - 1;
	while(i <= last)
	{
		half = (i + last) / 2;
		if(root->ch[half] == key)
		{
			return half;
		}
		else
		{
			if(root->ch[half] > key)
			{
				last = half - 1;
			}
			else
			{	
				i = half + 1;
			}
		}
	}
	return i;
}


