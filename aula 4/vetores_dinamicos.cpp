#include <stdio.h>
#include <stdlib.h>

int main(void){
	float x;
	int j;
	float i[5];
	
	printf("Insira 5 numeros para serem armazenados em um vetor:\n");
	
	for(j=0; j<5; j++){
		scanf("%f", &x);
		i[j] = x;
	}
	
	for(j=0; j<5; j++){
		printf("%f\n", i[j]);
	}
	
	return 0;
}
