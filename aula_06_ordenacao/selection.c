#include <stdio.h>
#include <stdlib.h>
#define MAX 10



void selection(int *v){
	int i, j, k, aux, troca;
	//k indica qual é o indice do menor numero

	for(i=0;i< MAX-1; i++){
		troca = 0;
		k = i;
		aux = v[i];
		
		for(j=i+1; j < MAX; j++){
			if(v[j] < aux){
				k = j;
				aux = v[j];
				troca = 1;
			}
		}
		
		if (troca == 1){
			//se foi encontrado que k é menor no segundo for, atribui o valor de k(j) no array com indice i(que é maior q v[k])
			v[k] = v[i];
			v[i] = aux;
		}
		
	}
}






int main(void){
	int i, vet[MAX];

	for(i=0;i < MAX; i++){
		printf("Informe o valor %d\n", (i+1));
		scanf("%d", &vet[i]);
	}
	
	selection(vet);
	
	printf("\nValores ordenados\n\n");
	
	for(i=0;i < MAX; i++){
		printf("%d\n", vet[i]);
	}
	
	return 0;
}
