#include <stdio.h>
#include <stdlib.h>
#include "auxpiramide.c"

int main(){
	float volume;
	volume = auxpiramide();
	
	printf("\n\n\n\nO volume da piramide informada � igual a:  ");
	printf("%f", volume);

	return 0;
}

