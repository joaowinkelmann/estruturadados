#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i, j;
	int mat[3][2];
	
	printf("Insira valores inteiros para alimentar a matriz: \n\n");
	for(i=0;i<3;i++){
		for(j=0;j<2;j++){
			printf("Insira um valor para a posicao (%d, %d)\n", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
	
	for(i=0;i<3;i++){
		for(j=0;j<2;j++){
			printf(" %d |", mat[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n\n\n Transposta:\n\n");	
	
	for(j=0;j<2;j++){
		for(i=0;i<3;i++){
			printf(" %d |", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
