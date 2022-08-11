#include <stdio.h>

int main(){
	int i = 10;
	int j;
	
	j = i++; //atribui, depois incrementa
	printf("%d\n", i);
	printf("%d\n", j);
	
	j = ++i; //incrementa, depois atribui
	printf("%d\n", i);
	printf("%d\n", j);
	
	return 0;
}
