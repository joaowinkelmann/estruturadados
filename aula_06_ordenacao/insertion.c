#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void insertion(int *v){
	int i, j, aux;
	
	for(i=1; i < MAX; i++){
		aux = v[i];
		
		for(j=i-1; j >= 0 && aux < v[j]; j--){
			v[j+1] = v[j];
		}
		
			v[j+1] = aux;
	}
	
}






int main(void){
	int i, vet[MAX];

	for(i=0;i < MAX; i++){
		printf("Informe o valor %d\n", (i+1));
		scanf("%d", &vet[i]);
	}
	
	insertion(vet);
	
	printf("\nValores ordenados\n\n");
	
	for(i=0;i < MAX; i++){
		printf("%d\n", vet[i]);
	}
	
	return 0;
}
