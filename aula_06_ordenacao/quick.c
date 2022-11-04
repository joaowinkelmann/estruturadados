#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void quick(int *v, int left, int right);

void quick(int *v, int left, int right){
	int i, j, x, y;
	
	i = left;
	j = right;
	x = v[(left + right) / 2];
	
	while(i <= j){
		
		while(v[i] < x && i < right){
			i++;
		}
		
		while(v[j] > x && j > left){
			j--;
		}
		
		if(i <= j){
			y = v[i];
			v[i] = v[j];
			v[j] = y;
			i++;
			j--;
		}	
	}
	
	if(j > left){
		quick(v, left, j);
	}
	if(i < right){
		quick(v, i, right);
	}
	
}






int main(void){
	int i, vet[MAX];

	for(i=0;i < MAX; i++){
		printf("Informe o valor %d\n", (i+1));
		scanf("%d", &vet[i]);
	}
	
	quick(vet, 0, MAX - 1);
	
	printf("\nValores ordenados\n\n");
	
	for(i=0;i < MAX; i++){
		printf("%d\n", vet[i]);
	}
	
	return 0;
}
