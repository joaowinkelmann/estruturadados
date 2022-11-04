#include <stdio.h>
#define MAX 10

void bolha(int *v){
	int i,j,aux;
	int troca = 0;
	for(i=0;i< MAX; i++){
		for(j=i+1; j < MAX; j++){
			if(v[j] > v[i]){
				aux = v[i];
				v[i] = v[j];
				v[j] =  aux;
			}
		}
	}
}

int main(void){
	int i, vet[MAX];

	for(i=0;i < MAX; i++){
		printf("Informe o valor %d\n", (i+1));
		scanf("%d", &vet[i]);
	}
	
	bolha(vet);
	
	printf("\nValores ordenados\n\n");
	
	for(i=0;i < MAX; i++){
		printf("%d\n", vet[i]);
	}
	
	return 0;
}
