#include <stdio.h>
#include <conio.h>

int main(void){
	int i, j, matriz[2][2] = {10,20,30,40};
	
	for (i=0;i < 2; i++){
		for (j=0; j < 2; j++){
			printf("matriz[%d][%d]: %d\n", i, j, matriz[i][j]);
		}
	}
	getch();
	return 0;
	
}
