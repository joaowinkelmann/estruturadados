/*
Programa para ler o nome de alguem
Autor: Joao Vitor Winkelmann
Data: 04/08/2022
Proposito: Receber o nome da pessoa que utiliza o programa.
*/

#include <stdio.h>

int main(){
	float c, f;
	printf("Insira a temperatura em celsius: \n");
	scanf("%f", &c);
	f = (1.8 * c) + 32;
	printf("Temperatura em F: %5.0f", f);
	return 0;
}
