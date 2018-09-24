/*
Biblioteca para desenhar a janela de interface
*/

#include "interface.h"

/*Colore a tela de interface*/
void recolor()
{

	gfx_clear();
	gfx_set_color( R, G, B);
	gfx_filled_rectangle( zero, zero, 1000, heightscreen);

}

/*Abre a janela de interface*/
void init_screen()
{

	gfx_init( 1000, heightscreen, "AB");
	recolor();
}


	
/*Desenha a arvore B*/
void screen(tree *pt, int half, int height, D *d, int flag)
{
	int i , x, x1, y, y1, aux;
   float k;
   char str[100];
	x = half;
	x1 = x + deltaX;
	y = height;
	y1 = y + deltaY;
	aux = flag;
	k = (pt->qtd_ch / 2) + 1;
	i = 0;

	
   if(pt != NULL) 
	{
			
  			while(i < pt->qtd_ch) 
			{
				
				gfx_set_color(214, 160, 206);
				gfx_filled_rectangle(x, y, x1, y1);
			
         	gfx_set_color(180, 140, 234);
         	gfx_rectangle(x, y, x1, y1);
     
    			gfx_rectangle(x + 1, y + 1, x1, y1);
         	sprintf(str, "%i", pt->ch[i]);
     
        		gfx_set_color( 132, 71, 245);
       		gfx_text (x + 2, y + 2, str);
     
        		x += deltaX;
       		x1 += deltaX;
         	i++;
			}
			
			i = 0;
			x = half;
   		while(i < ((2* (d->d)) + 1)) 
			{
         	if(pt->son[i] != NULL) 
				{
     				if(i < k) 
					{
               	aux = aux/2;
     					gfx_set_color(180, 140, 234);
                  gfx_line(x, y + deltaY, 10 + half - aux, height + 120);
                  
					}
     				else 
					{
            		gfx_set_color(180, 140, 234);
               	gfx_line(x, y + deltaY, 10 + half + aux, height + 120);
               	aux = aux*2;
            	}
        		}
         	x += deltaX;
         	i++;
     		}
	
   	i = 0;
   	aux = flag;
		while(i < pt->qtd_ch + 1) 
		{
   		if(pt->son[i] != NULL)
			{
     			if(i < k)
				{
         		aux = aux/2;
     				screen(pt->son[i], half - aux, height + 120, d, aux);
           
       		}
         	else
				{
					screen(pt->son[i], half + aux, height + 120, d, aux);
           		aux = aux*2;
				}
			}
			i++;
		}
	}
	

}



