#include <stdio.h>

void fat(int n){
	int i;
	int res = 1;
	for(i=1;i <= n;i++){
		res *= i;		
	}
	printf("O resultado foi igual a %d", res);
}

int main(){
	int n;
	printf("Insira o número a ser fatorializado\n");
	scanf("%d", &n);
	
	fat(n);
}
