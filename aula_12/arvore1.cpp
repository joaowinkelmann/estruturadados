#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int conteudo;
	struct no *esquerda, *direita;
} No;

typedef struct{
	No *raiz;
	int tam;
} ArvB;

void inserirDireita(No *no, int valor);

void inserirEsquerda(No *no, int valor){
	if(no->esquerda == NULL){
		No *novo = (No*)malloc(sizeof(No));
		novo->conteudo = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		no->esquerda = novo;
	} else{
		if(valor < no->esquerda->conteudo){
			inserirEsquerda(no->esquerda, valor);
		}
		if(valor > no->esquerda->conteudo){
			inserirDireita(no->esquerda, valor);
		}
	}
}

void inserirDireita(No *no, int valor){
	if(no->direita == NULL){
		No *novo = (No*)malloc(sizeof(No));
		novo->conteudo = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		no->direita= novo;
	}
	else{
		if(valor > no->direita->conteudo){
			inserirDireita(no->direita, valor);
		}
		if(valor < no->direita->conteudo){
			inserirEsquerda(no->direita, valor);
		}		
	}
}

void inserir(ArvB *arv, int valor){
	if(arv->raiz == NULL){
		No *novo = (No*)malloc(sizeof(No));
		novo->conteudo = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		arv->raiz = novo;
	}
	else{
		if(valor < arv->raiz->conteudo){
			inserirEsquerda(arv->raiz, valor);
		}
		if(valor > arv->raiz->conteudo){
			inserirDireita(arv->raiz, valor);
		}
	}
}

No* inserirNovaVersao(No *raiz, int valor){
	if(raiz == NULL){
		No *novo= (No*)malloc(sizeof(No));
		novo->conteudo = valor;
		novo->esquerda = NULL;
		novo->direita =  NULL;
		return novo;
	}
	else{
		if(valor < raiz->conteudo){
			raiz->esquerda = inserirNovaVersao(raiz->esquerda, valor);
		}
		if(valor > raiz->conteudo){
			raiz->direita  = inserirNovaVersao(raiz->esquerda, valor);
		}
		return raiz;
	}
}

int tamanho(No *raiz){
	if(raiz == NULL){
		return 0;
	}
	else{
		return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
	}
}

int buscar(No *raiz, int chave){
	if(raiz == NULL){
		return 0;
	}
	else{
		if(raiz->conteudo == chave){
			return 1;
		}
		else{
			return buscar(raiz->direita, chave);
		}
	}
}

void imprimir(No *raiz){
	if(raiz != NULL){
		imprimir(raiz->esquerda);
		printf("%d\n\n", raiz->conteudo);
		imprimir(raiz->direita);
	}
}

No *remover(No *raiz, int chave){
	if(raiz == NULL){
		printf("Valor nao encontrado!\n");
		return NULL;
	}
	else{
		if(raiz->conteudo == chave){
			if(raiz->esquerda == NULL && raiz->direita == NULL){
				free(raiz);
				return NULL;
			}
			else{
				if(raiz->esquerda == NULL || raiz->direita == NULL){
					No *aux;
					if(raiz->esquerda != NULL){
						aux = raiz->esquerda;
					}
					else{
						aux = raiz->direita;
					}
					free(raiz);
					return aux;
				}
				else{
					No *aux = raiz->esquerda;
					while(aux->direita != NULL){
						aux = aux->direita;
					}
					raiz->conteudo= aux->conteudo;
					aux->conteudo = chave;
					raiz->esquerda = remover(raiz->esquerda, chave);
					return raiz;
					}
				}
			}
			else{
				if(chave < raiz->conteudo){
					raiz->esquerda = remover(raiz->esquerda, chave);
				}
				else{
					raiz->direita = remover(raiz->direita, chave);
				}
		}
	return raiz;
	}
}

int main(){
	int op, valor;
	ArvB arv;
	arv.raiz = NULL;
	No *raiz = NULL;
	do{
		printf("\n0 - Sair\n1 - Inserir\n2 - Imprimir\n3 - Buscar\n4 - Remover\n\n");
		scanf("%d", &op);
		
		switch(op){
			case 0:
				printf("\nSaindo...\n");
				break;
			case 1:
				printf("\nDigite um valor:");
				scanf("%d", &valor);
				raiz = inserirNovaVersao(raiz, valor);
				
				//inserir(&arv, valor);
				
				break;
			case 2:
				printf("\nImpresao da arvore binaria:\n");
				imprimir(raiz);
				printf("\n");
				printf("Tamanho: %d\n", tamanho(raiz));
				break;
			case 3:
				printf("Qual o valor que deseja buscar?");
				scanf("%d", &valor);
				printf("\n\nResultado da busca: %d\n", buscar(raiz, valor));
				break;
			case 4:
				printf("Digite um mvalor a ser removido: ");
				scanf("%d", &valor);
				raiz = remover(raiz, valor);
				break;
			default:
				printf("Opcao nao encontrada");
				break;
		}
	}while(op != 0);
}



