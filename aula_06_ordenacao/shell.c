#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void shell(int *v, int size);

void shell(int *v, int size){
	int i, j, valor;
	int gap = 1;
	
	do{
		gap = 3*gap +1;
	}while(gap < size);
	
	do{
		gap /= 3;
	
		for(i = gap; i < size; i++){
			valor = v[i];
			j = i - gap;
			
			while(j >= 0 && valor < v[j]){
				v[j + gap] = v[j];
				j -= gap;
			}
			
			v[j + gap] = valor;
		}
		
	}while(gap > 1);
	
}






int main(void){
	int i, vet[MAX];

	for(i=0;i < MAX; i++){
		printf("Informe o valor %d\n", (i+1));
		scanf("%d", &vet[i]);
	}
	
	shell(vet, MAX);
	
	printf("\nValores ordenados\n\n");
	
	for(i=0;i < MAX; i++){
		printf("%d\n", vet[i]);
	}
	
	return 0;
}
