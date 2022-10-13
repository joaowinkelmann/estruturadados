#include <stdio.h>
#include <stdlib.h>

typedef struct No { //criação de nós / nodos
	int valor;
	struct No *proximo;
} No;

typedef struct  { //criação da estrutura da lista
	No *inicio, *fim; //ponteiros
	int tam;
} Lista;

void inserirInicio(Lista *lista, int valor){
	//parametro o endereço da lista, e o tipo de valor (Lista = estrutura, lista = ponteiro)
	No *novo = (No*)malloc(sizeof(No)); //comando para alocação de memória
	novo->valor = valor; //(*novo).valor = valor
	
	if(lista->inicio == NULL){ //verifica sea lista está vazia
		novo->proximo = NULL;
		lista->inicio = novo;
		lista->fim = novo;		
	}	
	else{ //A lista não está vazia
		novo->proximo = lista->inicio;
		lista->inicio = novo;
	}
	lista->tam++;
}

void inserirFim(Lista *lista, int valor){
	No *novo =  (No*)malloc(sizeof(No));
	novo->valor = valor;
	novo->proximo = NULL; //nulo pois é o ultimo elemento
	
	if(lista->inicio == NULL){
		lista->inicio = novo;
		lista->fim = novo;
	}
	else{
		lista->fim->proximo = novo;
		lista->fim = novo;
	}
	lista->tam++;
}

void imprimir(Lista *lista){
	No *inicio = lista->inicio;
	printf("Tamanho da  lista: %d\n\n", lista->tam);
	while(inicio != NULL){
		printf("%d ", inicio->valor);
		inicio = inicio->proximo;
	}
	printf("\n\n");
}

void remover(Lista *lista, int valor){
	No *inicio = lista->inicio;
	No *noARemover = NULL;
	
	if(inicio != NULL  && lista->inicio->valor == valor){
		noARemover = lista->inicio;
		lista->inicio = noARemover->proximo;
		if(lista->inicio == NULL){
			lista->fim  = NULL;
		} else { //remoção no meio ou no final
			while(inicio != NULL && inicio->proximo != NULL){
				inicio = inicio->proximo;
			}
			if(inicio != NULL && inicio->proximo != NULL){
				noARemover = inicio->proximo;
				inicio->proximo= noARemover->proximo;
				if(inicio->proximo == NULL){
					lista->fim = inicio;
				}
			}
		}
	}
	lista->tam--;
}


int main(void){
	Lista lista, listaI, listaP;
	int op;
	int val;
	
	//inicialização das listas
	lista.inicio = NULL;
	lista.fim = NULL;
	lista.tam = 0;
	
	listaI.inicio = NULL;
	listaI.fim = NULL;
	listaI.tam = 0;
	
	listaP.inicio = NULL;
	listaP.fim = NULL;
	listaP.tam = 0;
	
	printf("Insira a operacao desejada:");
	do{
	printf("\n1- Inserir no inicio\n2- Imprimir\n3- Inserir no Fim\n4- Remover um valor\n5- Sair\n");
	scanf("%d", &op);
	switch (op){
		case 1:
			printf("Insira o valor a ser inserido: ");
			scanf("%d", &val);
			inserirInicio(&lista, val);
			break;
		case 2:
			imprimir(&lista);
			break;
		case 3:
			printf("Insira o valor a ser inserido no fim: ");
			scanf("%d", &val);
			inserirFim(&lista, val);
			break;
		case 4:
			printf("Insira um valor a ser removido: ");
			scanf("%d", &val);
			remover(&lista, val);
			break;
	}
	
	}while(op != 5);
	return 0;	
}
