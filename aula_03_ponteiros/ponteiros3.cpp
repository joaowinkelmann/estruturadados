#include <stdio.h>

int main(void){
	int x;
	int *p1, *p2;
	
	p1 = &x;
	p2 = p1;
	
	printf("endere�o de p1: %x\n", p1);
	printf("endere�o de p2: %x\n", p2);
	printf("endere�o de x: %x\n", &x);
	return 0;
}
