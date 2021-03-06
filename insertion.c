#include "insertion.h"


/*Insere uma chave e o ponteiro para  o filho da direita de um no*/
void insertKey(tree *root, int key, tree *noright)
{
	int k, pos;
	/*busca para obter a posicao ideal para inserir a nova chave*/
	pos = binarysearch( root, key);
	k = root->qtd_ch;

	/*realiza o remanejamento para manter as chaves ordenadas*/
	while(k > pos && key < root->ch[k - 1])
	{
		root->ch[k] = root->ch[k - 1];
		root->son[k + 1] = root->son[k];
		k--;
	}
	/*insere a chave na posicao ideal*/
	root->ch[pos] = key;
	root->son[pos + 1] = noright;
	root->qtd_ch++;
}

tree *split(tree *root, tree *right_son, int *back, D *pt)
{
	register int i;
	tree *temp;

	temp = (tree *) malloc (sizeof(tree));
	temp->qtd_ch = 0;
	
	for(i = 0; i < root->qtd_ch + 1; i++)
	{
		temp->son[i] = NULL;
	}
	
	insertKey(root, *back, right_son);

	/*Mediano sobe*/
	*back = root->ch[pt->d];

	/*primeira metade no temp*/
	temp->son[0] = root->son[pt->d + 1];

	for(i = pt->d + 1; i < root->qtd_ch; i++)
	{
		insertKey(temp, root->ch[i], root->son[i + 1]);
	}

	/*atualiza no raiz e redistribui as chaves*/
	for(i = pt->d; i < pt->m; i++)
	{
		root->ch[i] = 0;
		root->son[i + 1] = NULL;
	}
	root->qtd_ch = pt->d;

	return temp;


}


/*realiza a busca do no para inserir a chave e faz as subdivisoes quando necessario*/
tree *insert(tree *root, int key, bool *h, int *returnkey, D *pt)
{
	int pos;
	tree  *noright;
	if(root == NULL)
	{
		*h = true;
		*returnkey = key;
		return NULL;
	}
	else 
	{
		pos =  binarysearch( root, key);
		if(root->qtd_ch > pos && root->ch[pos] == key)
		{
			printf("Chave ja existe na posicao %d\a\n", pos);
			*h = false;
		}
		else
		{
			/*desce ate encontar a pagina folha para inserir a chave*/
			noright = insert(root->son[pos], key, h, returnkey, pt);
			if(*h)/*se for true deve inserir o returnkey na pagina*/
			{
				if(root->qtd_ch < pt->m)
				{
					insertKey( root, *returnkey, noright);
					*h = false;
				}
				else/*Split -> dividir a page em duas e redistribuir as chaves.*/ 
				{
					return split(root, noright, returnkey, pt);
				}
			}
		
		}
		return root;
	}
	
}
tree *insertB(tree *root, int key, D *pt)
{
	bool h;
	int returnkey, i;
	tree *noright, *new_root;
	noright =  insert(root, key, &h, &returnkey, pt);
	
	if(h)
	{
		new_root = (tree *) malloc (sizeof(tree));
		new_root->qtd_ch = 1;
		new_root->ch[0] = returnkey;
		new_root->son[0] = root;
		new_root->son[1] = noright;
		for(i = 2; i <= pt->m; i++)
		{
			new_root->son[i] = NULL;
		}
		return new_root;
	}
	else return root;

}

void emordem(tree *raiz)
{
	int i;
	if(raiz != NULL)
	{
		for(i=0;i<raiz->qtd_ch; i++)
		{			
			emordem(raiz->son[i]);
			printf("\n%d\n", raiz->ch[i]);
			if(raiz->son[i] != NULL)
				printf("ponteiro ok\n");
		}
		emordem(raiz->son[i]);
	}

}


