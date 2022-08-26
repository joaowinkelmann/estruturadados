#include <stdio.h>
#include <stdlib.h>

int main(void){
	int a=0;
	printf("Imprimindo os caracteres do padrao ascii");
	
	for(a=1;a<255;a++){
		printf("Decimal: %i   Octal: %o  Hexadecimal: %x   Caractere: %c\n", a, a, a, a);
	}
		printf("\n\n\n\n FIM");
}
