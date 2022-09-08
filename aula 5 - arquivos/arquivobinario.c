#include <stdio.h>
#include <stdlib.h>

int main(void){
	char ch[15] = "Bem pogegers";
	int valor[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	FILE *pont_arq;
	
	pont_arq = fopen("arqbin.bin", "wb");
	
	if (pont_arq == NULL){
		printf("Erro ao escrever o arquivo binario");
		exit(1);
	}
	else{
		printf("Arquivo escrito com sucesso");
	}
	
	fwrite(ch, sizeof(char), 15, pont_arq);
	fwrite(valor, sizeof(int), 15, pont_arq);
	fclose(pont_arq);
	
	system("pause");
	return 0;
}
