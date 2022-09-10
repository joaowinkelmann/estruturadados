// Exercício 8
// DESCRIÇÃO
// - Funções
// - Ponteiros

#include <stdio.h>
#include <locale.h>
#define MAX 5

float encontraRaizes(float v, float *res){
    int i;
    float aux;
    for(i=0; i < MAX; i++){
        res[i] =v[i];
    }
}

int main(void){
    float vet[MAX];
    float result[MAX];
    int i;
    setlocale(LC_ALL, "");
    printf("Insira %d valores para receber as suas raízes", MAX);
    for(i=0; i < MAX; i++){
        printf("Insira o valor [%d]", i);
        scanf("%d", &vet[i]);
    }

    encontraRaizes(vet, result);

    //retorna o vetor para o usuario
    for(i=0; i < MAX; i++){
        printf("%lf \t| ", vet[i]);
    }

    return 0;
}