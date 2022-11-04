#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 5

int main(void){
	setlocale(LC_ALL, "");
	int i;
	int vet[MAX];
	int soma = 0;
	int pares = 0;
	
	printf("Insira %d valores inteiros\n\n", MAX);
	for(i=0;i<MAX;i++){
		printf("Insira o valor %d\n", i);
		scanf("%d", &vet[i]);
		soma = soma + vet[i];
	}
	
	printf("\n\n A soma foi igual a %d", soma);
	
	
	for(i=0;i<MAX;i++){
		if((vet[i] % 2) == 0){
			pares++;
		}
	}
	
	printf("\n\nO total de pares são de %d\n", pares);
	printf("Já o total de ímpares são de %d", (MAX - pares));
	return 0;
}
