#include <stdio.h>
#include <stdlib.h>

struct Pilha{
	int topo;
	int capa;
	float *pElem;
};

void criarpilha( struct Pilha *p, int c){
	p->topo = -1;
	p->capa = c;
	p->pElem = (float*) malloc (c *sizeof(float));
}
