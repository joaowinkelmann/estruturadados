#include <stdio.h>
#define PI 3.14592

float calculaCilindro(float raio, float altura, float &volume){
	volume = (PI*raio*raio*altura);
	return volume;
}

int main(){
	float raio, altura, volume;
	printf("Insira o raio do cilindro:\n");
	scanf("%f", &raio);
	printf("Insira a altura do cilindro:\n");
	scanf("%f", &altura);
	calculaCilindro(raio, altura, volume);
	
	printf("Volume: %f", volume);
	return 0;	
}
