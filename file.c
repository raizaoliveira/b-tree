#include "file.h"

/*Salva  arquivo*/
void savefile(tree **root ,FILE *p)
{
	register int i;
	if(root != NULL)
	{
		fwrite(*root, sizeof(tree), 1, p);
		i = 0;
		
		while(i < (*root)->qtd_ch + 1) 
		{
			if((*root)->son[i] != NULL)
			{
      	   savefile(&((*root)->son[i]), p);
			}
			i++;
		}
	}
}

/*abre arquivo binario de arvore B*/
tree *openfile(FILE *p)
{
	int i;
	tree *ptno = (tree *) malloc (sizeof (tree));
	
	if(fread (ptno, sizeof(tree), 1, p) == 0)
	{
		free(ptno);
		return NULL;
	}
	else
	{
		i = 0;
		while(i <= ptno->qtd_ch)
		{
			if(ptno->son[i] != NULL)
			{
        		ptno->son[i] = openfile(p);
			}
			else
				ptno->son[i] = NULL;
			
		i++;
		}
		return ptno;

	}

}

