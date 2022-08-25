#include <stdio.h>

int main(){
	int matrix[20][20];
	int l,c;
	int count = 1;
	
	for(l=0;l<20;l++){
		for(c=0;c<20;c++){
			matrix[l][c] = count;
			count++;
		}
	}
	
	for(l=0;l<20;l++){
		for(c=0;c<20;c++){
			printf(" %.3d ", matrix[l][c]);
		}
		printf("\n");
	}
}
