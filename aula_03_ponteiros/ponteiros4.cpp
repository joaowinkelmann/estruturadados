#include <stdio.h>
#include <stdlib.h>

int main(void){
	int x, *ptr, **pptr;
	
	x = 0;
	printf("Valor de X: %d\n", x);
	printf("Endere�o de X: %x\n", &x);
	
	ptr = &x;
	pptr = &ptr;
	
	*ptr = *ptr + 10;
	printf("Valor de X: %d\n", x);
	printf("Endere�o apontado por ptr %x\n", ptr);
	printf("Valor da variavel X apontada por ptr: %d\n", *ptr);
	printf("Endere�o de mem�ria do ponteiro ptr: %x\n\n", &ptr);
	
	**pptr = **pptr + 10;
	
	printf("Valor de X: %d\n", x);
	printf("Endere�o apontado por ptr %x\n", pptr);
	printf("Valor da variavel X apontada por ptr: %d\n", **pptr);
	printf("Endere�o de mem�ria do ponteiro ptr: %x", &pptr);
	
	return 0;
}
