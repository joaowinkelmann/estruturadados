#include <stdio.h>
#include "g_valor.c"

int main(){
	int aux = g_valor();
	
	printf("\n %d", aux);
	getch();
	
	return 0;
}
