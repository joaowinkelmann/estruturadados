// Exercício 10
// Contador de vogais
// Escolher entre as funções de abrir e fechar arquivos, estruturação de dados em arquivos de texto
// e arquivos em modo binário para criar o seu algoritmo.

#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *pont_texto;
    char str_entrada[100];
    char c;
    int vogais = 0;
	pont_texto = fopen("textousuario.txt", "a");

    if (pont_texto == NULL){
		printf("Erro ao tentar manipular o arquivo");
        exit(1);
	}
    else{
        printf("Arquivo inicializado com sucesso\n\n");
    }

    printf("Insira os dados a serem adicionados no final do arquivo: ");
    fgets(str_entrada, 100, stdin);
    fprintf(pont_texto, "%s \n", str_entrada);
    printf("\n\nArquivo editado com sucesso\n\n");
    fclose(pont_texto);

    printf("Visualização do arquivo:\n\n");
    pont_texto = fopen("textousuario.txt", "r");
   while((c = fgetc(pont_texto))!=EOF) {
        if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U'){
            vogais++;
        }
        putchar(c);
    }

    printf("\n\n Existem %d vogais no arquivo de texto", vogais);

    fclose(pont_texto);
    return 0;
}