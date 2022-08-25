#include <stdio.h>
#include <stdlib.h>

int main(void){

	int i;
	int fib[10];
	fib[0] = 1;
	fib[1] = 1;
	
	for(i=2;i<10;i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
	for (i=0;i<10;i++){
		printf("%d\n", fib[i]);
	}
}
