#include <stdio.h>
#include <conio.h>

int main(){
	int a;
	int *p;
	
	p = &a;
	*p = 6;
	
	printf("%d\n", a);
	
	return 0;
}
