#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,j;
	int vet[10][10];
	
	vet[0][0] = 1;
	
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			vet[i][j] = ((vet[i-1][j-1]) + 1);
		}
	}
	
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			printf("| %d ", vet[i][j]);
		}
		printf("| \n");
	}
	return 0;
}
