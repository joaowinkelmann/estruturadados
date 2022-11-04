#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int somaNum(int a, int b){
	int resultado;
	
	resultado = a + b;
	
	return resultado;
}

int main(void){
	int x;
	int y;
	int soma;
	
	printf("Insira 2 números inteiros a serem somados\n\n");
	printf("Insira o primeiro número:\n");
	scanf("%d", &x);
	printf("Insira o segundo número:\n");
	scanf("%d", &y);
	
	soma = somaNum(x,y);
	
	//soma = x + y;
	
	printf("\n\n A soma dos números é igual a %d", soma);
		
	return 0;
}
