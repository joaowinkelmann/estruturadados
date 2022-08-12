#include <stdio.h>
#include <math.h>


int main(){
	char op;
	float x,y;
	
	printf("Insira o primeiro numero:");
	scanf("%f", &x);
	printf("Agora insira o segundo numero:");
	scanf("%f", &y);
	printf("Insira a operacao desejada: (+, -, /, *)");
	scanf("%s", &op);
	
	switch (op){
		case '+':
			printf("%f", x+y);
			break;
		case '-':
			printf("%f", x-y);
			break;
		case '*':
			printf("%f", x*y);
			break;
		case '/':
			printf("%f", x/y);
			break;
		default:
			printf("Operacao invalida");
	}
	
	return 0;
}
