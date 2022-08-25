#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n, i;
	float xi;
	float s = 0.0f;
	
	printf("Insira o numero de valores:\n");
	scanf("%d", &n);
	
	printf("Agora insira os valores:\n");
	
	for(i=0;i<n; ++i){
		scanf("%f", &xi);
		s += xi;
	}
	float m = s/n;
	printf("Media: %.2f\n", m);
	
	return 0;
}
