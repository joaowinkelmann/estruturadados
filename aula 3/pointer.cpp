#include <stdio.h>
#include <conio.h>

int main(){
	int valor = 257;
	
	int *ptr;
	
	ptr = &valor;
	
	printf("Conteudo da variavel valor: %d \n", valor);
	printf("Endere�o da variavel valor: %x \n", &valor);
	printf("Conte�do da variavel ponteiro ptr: %x \n", ptr);
	getch();
	
	return 0;
}
