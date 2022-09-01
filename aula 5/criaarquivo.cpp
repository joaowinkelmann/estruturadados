#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *pont_arq;
	//abrir o arquivo
	pont_arq = fopen("arquivo.txt", "a");
	//fechar o arquivo
	fclose(pont_arq);
	//mensagem para o usuario
	printf("O arquivo foi criado com sucesso");
	system("pause");
	return 0;
}
