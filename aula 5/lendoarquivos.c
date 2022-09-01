#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *pont_arq;
	pont_arq = fopen("arquivo4.txt", "r");
	char c;
	
	if (pont_arq == NULL){
		printf("Erro ao tentar criar o arquivo");
		exit(1);
	}

	do
	{
		c = fgetc(pont_arq);
		printf("%c", c);
	}while (c != EOF);
	
	//EOF -> caractere que indica o fim do aquivo 
	
	fclose(pont_arq);
	system("pause");
	return 0;
}
