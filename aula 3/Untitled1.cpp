#include <stdio.h>

float c_para_f(float c){
	float f;
	f = 1.8 * c + 32;
	
	return f;
	
}

int main(){
	float f, c;
	printf("Insira o valor em celsius:\n");
	scanf("%f", &c);
	f = c_para_f(c);
	printf("O resultado é igual a %f", f);
	return 0;
}
