#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	float v[6] = {2.3,7.8,4.3,6.3};
	float s = 0.0;
	int i;
	for(i=0;i<6;i++){
		s = s + v[i];
	}
	printf("%f", s);
}
