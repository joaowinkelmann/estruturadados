#include <stdio.h>
#include <stdlib.h>

//Listas  Lineares Encadeadas
//Rotinas de Manipulação Lista Simplesmente Encadeada

//pList -> ponteiro de lista

struct Nodo{
	int info;
	struct Nodo *prox; 
};

struct ListaSimplesEnc{
	struct Nodo *prim;
};

void criarLista (struct ListaSimplesEnc *pList){
	pList -> prim = NULL; //recebe atribuindo (ponteiro pList recebe a variavel 'prim', esta que possui o valor NULL
}

void mostrarLista(struct ListaSimplesEnc *pList){
	struct Nodo *p;
	for(p = pList -> prim; p != NULL; p = p->prox){
		printf("%d\t", p->info);
	}
	printf("\n");
}

void  inserirIni (struct ListaSimplesEnc *pList, int v){
	struct Nodo *novo;
	novo = (struct Nodo*) malloc (sizeof (struct Nodo));
	novo -> info = v;
	novo -> prox = pList -> prim;
	pList -> prim = novo;
}

int estaVazia(struct ListaSimplesEnc *pList){
	return(pList->prim == NULL);
}

int main(void){
	struct ListaSimplesEnc minhaLista;
	int valor,  op;
	
	criarLista(&minhaLista);
	
	while(1){
		
		printf("1 - Inserir elemento no inicio\n");
		printf("2 - Mostrar lista\n");
		printf("3 - Sair\n");
		printf("Opcao? ");
		scanf("%d", &op);
		
		switch(op){
			case 1: //inserir elementoo no inicio
				printf("Inserir um valor? ");
				scanf("%d", &valor);
				inserirIni(&minhaLista, valor);				
				break;
			case 2:  //mostrar lista
				if(estaVazia(&minhaLista)){
					printf("Lista vazia");
				}
				else{
					mostrarLista(&minhaLista);
				}
				break;
			case 3: //sair
				exit(0);
		}
	}
	return 0;
}
