#include <stdio.h>
#include <conio.h>

int main(){
	int valor = 257;
	
	int *ptr;
	
	ptr = &valor;
	
	printf("Conteudo da variavel valor: %d \n", valor);
	printf("Endereço da variavel valor: %x \n", &valor);
	printf("Conteúdo da variavel ponteiro ptr: %x \n", ptr);
	getch();
	
	return 0;
}
