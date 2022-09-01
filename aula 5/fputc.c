#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *pont_arq;
	pont_arq = fopen("arq2.txt", "w");
	int tamanho;
	int i;
	char frase[50];
	
	if (pont_arq == NULL){
		printf("Erro ao gerar o arquivo");
		exit(1);
	}
	
	printf("Insira a frase a ser gravada no arquivo");
	gets(frase);
	
	//pega o tamanho da string
	tamanho = strlen(frase);
	
	for(i=0; i < tamanho; i++){
		fputc(frase[i], pont_arq);
	}
	fclose(pont_arq);
	return 0;
}
