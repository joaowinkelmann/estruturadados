#include <stdio.h>
#include <stdlib.h>

//Listas  Lineares Encadeadas
//Rotinas de Manipulação Lista Simplesmente Encadeada

struct Nodo{
	int info;
	struct Nodo *prox; 
}

int main(void){
	struct ListaSimplesEnc minhLista;
	int valor,  op;
	
	criarLista(&minhaLista);
	
	while(1){
		
		printf("1 - Inserir elemento no inicio\n");
		printf("2 - Mostrar lista\n");
		printf("3 - Sair\n");
		printf("Opcao? ");
		
	}
}
