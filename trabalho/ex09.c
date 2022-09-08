//Exercício 9
//Diagonal secundária de uma matriz em um vetor
// 9. Seguintes itens:
// - Vetores
// - Matrizes

#include <stdio.h>
#include <locale.h>

void Diag_sec (float M[][5]){
    int i, j;
    int k = 0;
    float V[5];
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(i+j==4)
            V[k] = M[i][j];
            k++;
        }
    }

    for(i=0;i<5;i++){
        printf("%.2f ", V[i]);
    }

}

int main() {
    setlocale(LC_ALL, "Portuguese");

    float M[5][5];
    int i, j;

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            printf("Digite um número para a posicao %d %d", i, j);
            scanf("%f", &M[i][j]);
        }
    }
    
    Diag_sec(M);

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            printf("%.2f |\t", M[i][j]);
        }
        printf("\n");
    }

}


