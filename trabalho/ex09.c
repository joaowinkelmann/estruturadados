// Exercício 9
// Encontrar a diagonal secundária de uma matriz e armazenar em um vetor
// 9. Seguintes itens:
// - Vetores
// - Matrizes

#include <stdio.h>
#include <locale.h>
#define MAX 5

void Diag_sec (float M[][MAX], float *v){
    int i, j;
    int k = 0;
    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++){
            if(i+j==(MAX - 1)){
                v[k] = M[i][j];
                k++;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "");

    float M[MAX][MAX];
    float vet[MAX];
    int i, j;

    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++){
            printf("Digite um número para a posicao [%d, %d]: ", i, j);
            scanf("%f", &M[i][j]);
        }
    }
    
    Diag_sec(M, vet);

    //imprime a matriz informada pelo usuario
    printf("\nMatriz informada:\n\n");
    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++){
            printf("%.2f |\t", M[i][j]);
        }
        printf("\n");
    }

    //imprime o vetor gerado
    printf("\nVetor formado pela diagonal secundária da matriz:\n\n");
    for(i=0; i<MAX; i++){
        printf("%.2f |\t", vet[i]);
    }

}


