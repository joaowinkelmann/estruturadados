/*
Programa para ler o nome de alguem
Autor: Joao Vitor Winkelmann
Data: 04/08/2022
Proposito: Receber o nome da pessoa que utiliza o programa.
*/

#include <stdio.h>

int main(){
	float n1, n2, n3, media;
	
	printf("Insira a nota 1: \n");
	scanf("%f", &n1);
	printf("Insira a nota 2: \n");
	scanf("%f", &n2);	
	printf("Insira a nota 3: \n");
	scanf("%f", &n3);
	
	media = (n1 + n2 + n3)/3;
	printf("Media: %f", media);
	
	if (media > 7){
		printf("\nO aluno foi aprovado");
	}
	else {
		printf("\nO aluno nao foi aprovado");
	}
}
