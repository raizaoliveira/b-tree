
/*
Gerenciamento de uma arvore B
Aluna: Raiza Arteman
RGM: 023428
Algoritmo e Estruturas de Dados II
Universidade Estadual de Mato Grosso do Sul

*/


#include "auxb.h"
#include "gfx.h"
#include "interface.h"
#include "file.h"
#include "insertion.h"
#include "used.h"
#include "del.h"
#include <time.h>

void menu()
{
	int c, i;
	int resp, retu;
	char str[100];
	FILE *p;
	tree *root;
	tree *aux;
	D info;
	bool h;
	char buffer[10];
	root = NULL;

	init_screen();
	
	aux = (tree*) malloc(sizeof(tree));

	init_tree(&info);


	

	do{
		puts("1- inserir\n2- buscar\n3-Deletar\n4- Salvar\n5- Abrir \n6-Destruir \n7- Sair \n");
		do{
			printf("->    ");
			scanf(" %c", buffer);
			resp = atoi(buffer);
		}while((resp < 0) || (resp > 7));
		switch(resp)
		{
			srand(time(NULL));
			case 1:
				printf("digite a chave a ser inserida: ");
				scanf(" %d", &c);
				for(i = 0; i < 10; i++)
					root = insertB(root, rand()%999, &info);
				break;

			case 2:
				printf("digite a chave a ser buscada: ");
				scanf(" %d", &c);
				aux = pageX(root, c, &h, &retu, &info);
				if (aux!= NULL)
					puts("Chave encontrada\a");
				else puts("chave nao existe");
				break;

			case 3:
				printf("digite a chave a ser deletada: ");
				scanf(" %d", &c);
				root = delete(root, c, &info);
				break;

			case 4:
					/*Salva o arquivo*/
               printf("Informe o nome do arquivo:  ");	
					scanf(" %s", str);

					p = fopen(str, "w+b");
					if(!p)
					{
						puts("Nao abriu");
					}
					else
					{
						savefile(&root, p);
						fclose(p);
					}
					break;
			case 5:
					/*Abre arquivo*/
					printf("Informe o nome do arquivo: ");
					scanf(" %s", str);
					p = fopen(str, "rb");
					if(!p)
					{
						puts("Nao abriu");
					}
					else
					{
						
						root = openfile(p);
						fclose(p);
					}
					break;
			case 6:
					delet(&root);
					break;
				
		}
	recolor();
	if(root != NULL)
		screen(root, 500, deltaX, &info, 500);
	else		
		gfx_text(500, 50, "NULL");
	
	/*printf("\33[H\33[2J");*/

	}while(resp != 7);
	if(root != NULL)
		delet(&root);
	gfx_quit();

}

int main()
{

	menu();


	return 0;


}
