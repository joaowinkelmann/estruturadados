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
	
	printf("Insira 2 n�meros inteiros a serem somados\n\n");
	printf("Insira o primeiro n�mero:\n");
	scanf("%d", &x);
	printf("Insira o segundo n�mero:\n");
	scanf("%d", &y);
	
	soma = somaNum(x,y);
	
	//soma = x + y;
	
	printf("\n\n A soma dos n�meros � igual a %d", soma);
		
	return 0;
}
