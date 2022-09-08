#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *pont_arq; //criar o texto
	char palavra[20];
	
	pont_arq = fopen("arquivo_palavra.txt", "w");
	//testar se o arquivo foi realmente criado
	if(pont_arq == NULL){
		printf("Erro na abertura do arquivo");
		return 1;
	}
	printf("Insira algo para ser adicionado ao arquivo");
	scanf("%s", &palavra);
	fprintf(pont_arq, "%s", palavra);
	fclose(pont_arq);
	printf("Arquivo editado com sucesso");
	system("pause");
	return
}
