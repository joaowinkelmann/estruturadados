#include <stdio.h>
#include <locale.h>

int main(void){
	char *string[6]={"Avi�o", "Mam�o", "Cora��o", "A��car", "�rvore", "L�mpada"};
	int i;
	//USO DA BIBLIOTECA
	setlocale(LC_ALL,"");
	
	for(i=0;i<6;i++){
		printf("%s\n", string[i]);
	}
	return 0;
}
