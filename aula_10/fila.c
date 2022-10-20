#include <stdio.h>
#include <stdlib.h>
//Filas - Queue

struct Fila{
	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens;
};

void criarFila(struct Fila *f, int c){
	f->capacidade = c;
	f->dados = (float*) malloc (f->capacidade * sizeof(float));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0;
}

void inserir(struct Fila *f, int v){
	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;
	f->ultimo++;
	f->dados[f->ultimo] = v; //incrementa o ultimo e insere
	f->nItens++; // mais um item inserido
}

int remover ( struct Fila *f){
	int temp = f->dados[f->primeiro++];
	if(f->primeiro == f->capacidade)
		f->primeiro = 0;
		
	f->nItens--;
	return temp;
}

int estaVazia ( struct Fila *f){
	return (f->nItens==0); // verdadeiro somente se não houver nenhum item dentro da lista
}

int estaCheia ( struct Fila *f){
	return (f->nItens == f->capacidade);
}

void mostrarFila( struct Fila *f){
	int cont, i;
	for(cont=0, i= f->primeiro; cont < f->nItens; cont++){
		printf("%.2f\t", f->dados[i++]);
		if(i == f->capacidade){
			i = 0;
		}
	printf("\n\n");
	}
}

int main(void){
	int opcao, capa;
	float valor;
	struct Fila umaFila;
	
	//cria a fila
	printf("\nCapacidade da fila? ");
	scanf("%d", &capa);
	criarFila(&umaFila, capa);
	
	//apresenta menu
	while(1){
		printf("\n1-Inserir um elemento\n2-Remover elemento\n3-Mostrar fila\n0-Sair\nOpcao?");
		
		scanf("%d", &opcao);
		
		switch(opcao){
			case 0: exit(0); //sair
			case 1: //insere
				if(estaCheia(&umaFila)){
					printf("\nErro: Fila cheia\n\n");
				}
				else {
					printf("\nInsira o valor a ser inserido: \n");
					scanf("%f", &valor);
					inserir(&umaFila, valor);
				}
				break;
			case 2: //remover
				if(estaVazia(&umaFila)){
					printf("\nErro: Fila vazia\n\n");
				}
				else{
					valor = remover(&umaFila);
					printf("\n%1f removido com sucesso\n\n");
				}
				break;
			case 3: //mostra
				if(estaVazia(&umaFila)){
					printf("\nErro: Fila vazia\n\n");
				}
				else{	
					mostrarFila(&umaFila);
				}
				break;
			default:
				printf("\n\nErro: Opcao nao encontrada\n\n\n");
			}
		}
	}
