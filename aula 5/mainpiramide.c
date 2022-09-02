#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "auxpiramide.c"

int main(){
	float volume;
	volume = auxpiramide();
	
	printf("\n\n\n\nO volume da piramide informada eh igual a:\a\a  ");
	printf("%f", volume);

	MessageBeep(MB_OK);
	
	return 0;
}

