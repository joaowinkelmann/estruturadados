#include <stdio.h>
#include <locale.h>
#define MAX 3

void Exponencial(int *v){
	int i,j,aux;
	for(i=0;i< MAX; i++){
        v[i] *= (5*v[i])/2;
	}
}

int main(void){
    setlocale(LC_ALL, "");
	int i, vet[MAX];
    printf("Insira %d valores para serem calculados\n\n", MAX);

	for(i=0;i < MAX; i++){
		printf("Informe o valor %d\n", (i+1));
		scanf("%d", &vet[i]);
	}
	
	Exponencial(vet);
	
	printf("\nResultado da operação:\n\n");
	
	for(i=0;i < MAX; i++){
		printf("%d\n", vet[i]);
	}
	
	return 0;
}