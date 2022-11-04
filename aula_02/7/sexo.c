#include <stdio.h>

int main(){
	char sexo[1];
	char nome[50];
	int i;
	int contamasc = 0;
	int contafem = 0;
	printf("Insira o nome e sexo de 10 pessoas\n");
	
	for(i=0;i<10;i++){
		printf("Insira o seu nome:");
		scanf("%s", &nome);
		printf("Agora insira o seu sexo: (M/F)");
		scanf("%s", &sexo);
		
		if (sexo=='F'){
			contafem = contafem + 1;
		}
		else{
			contamasc = contamasc + 1;
		}

	}
	
	printf("Existem %d pessoas com o sexo masculino\n", contamasc);
	printf("E %d pessoas com o sexo feminino", contafem);
	return 0;
}
