#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node *prox;
};

typedef stuct Node node;

int tam;

int menu(void);
void opcao(node *FILA, int op);
void inicia(node *FILA);
void vazia(node *FILA);
node * aloca();
void insere(node *FILA);
node *retira(node *FILA);
void exibe(node *FILA);
void libera(node *FILA);
