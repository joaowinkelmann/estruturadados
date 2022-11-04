#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *pont_arq;
	int r;
	pont_arq = fopen("arquivo3.txt", "w");
	
	if (pont_arq == NULL){
		printf("Erro ao tentar manipular o arquivo");
	}
	
	r = fputs("Programando em linguagem C", pont_arq);
	
	//verificacao
	if (r == EOF){
		printf("Erro ao tentar gravar os arquivos");
	}
	else{
		printf("Dados gravados com sucesso");
	}
	return 0;
	
}

