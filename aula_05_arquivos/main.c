#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int a,b,c;
	
	
	printf("Informe o primeiro valor: \n", &a);
	scanf("%d", &a);
	printf("Informe o segundo valor: \n", &b);
	scanf("%d", &b);

	c = a + b;
	
	printf("%d", c);
	system("pause");
	return 0;
}
