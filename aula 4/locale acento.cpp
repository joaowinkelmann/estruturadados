#include <stdio.h>
#include <locale.h>

int main(void){
	char *string[6]={"Avião", "Mamão", "Coração", "Açúcar", "Árvore", "Lâmpada"};
	int i;
	//USO DA BIBLIOTECA
	setlocale(LC_ALL,"");
	
	for(i=0;i<6;i++){
		printf("%s\n", string[i]);
	}
	return 0;
}
