
/*
Biblioteca para a interface grafica.
*/
#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "auxb.h"
#include "gfx.h"

#define width 1000
#define heightscreen 600
#define halfx 500
#define heightofy 30
#define deltaX 30
#define deltaY 20
/*RGB representa a cor de fundo da janela*/
#define R 175
#define G 176
#define B 199
#define zero 0

void screen(tree *pt, int half, int height, D *d, int flag);

void init_screen();

void recolor();

#endif

