#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *pont_arq;
	char texto_str[20];
	
	pont_arq = fopen("arquivo5.txt", "r");
	
	//laço para leitura fgets
	while(fgets(texto_str, 20, pont_arq) != NULL);
	printf("%s", texto_str);
	
	fclose(pont_arq);
	system("pause");
	return 0;
	
}
