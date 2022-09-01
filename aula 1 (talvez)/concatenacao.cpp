/*
Programa para ler o nome de alguem
Autor: Joao Vitor Winkelmann
Data: 04/08/2022
Proposito: Receber o nome da pessoa que utiliza o programa.
*/

#include <stdio.h>
#include <string.h>

int main(){
	char string1[10];
	char string2[20];
	
	strcpy(string1, "Linguagem");
	strcpy(string2, " de Programacao C");
	
	strcat(string1, string2);
	
	printf("%s", string1);
	return 0;
}
