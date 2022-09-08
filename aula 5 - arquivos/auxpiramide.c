#include <stdio.h>
#include <stdlib.h>

float auxpiramide(){
	float aresta;
	float aBase;
	float altura;
	printf("Insira a aresta da base da piramide quadrada:\n ");
	scanf("%f", &aresta);
	
	aBase = (aresta * aresta);
	
	printf("Agora insira a altura da piramide: \n");
	scanf("%f", &altura);
	
	return ((aBase * altura) / 3);
}
