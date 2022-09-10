// Exercício 7
// Programa para encontrar a sequência de fibonacci e números primos abaixo de um limite informado pelo usuário.
// - While
// - For
// - Do/while
// - break e continue

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

int main(void){
    setlocale(LC_ALL, "");
    int i;
    char decisao;

    while (decisao != 's'){
        printf("Entre com um número para fazer a sua escolha:\n");
        printf("f - Sequência de fibonacci\np - Ecnontrar números primos\ni - Econtrar pares e impares\ns - Sair do programa\n");
        scanf("%c", &decisao);

        switch(decisao){
            case 'f':
                int x = 0;
                int y = 1;
                int z = 1;
                int maxFib;
                printf("Opção 'Sequência de fibonacci' selecionada.\nEntre com um número para ser o limite da operação:\n");
                scanf("%d", &maxFib);

                do{
                    i++;
                    printf("%d. %d\n", i, z);
                    z = x + y;
                    x = y;
                    y = z;
                } while (maxFib >= z);

                break;
            case 'p':
                int num;
                int index = 1;
                bool primo;
                printf("Opção 'Números primos' selecioanda.\nEntre com um número para ser o limite da operação:\n");
                scanf("%d", &num);

                if (num <= 2){
                    printf("O número precisa ser maior que 2\nAssumindo como parâmetro o número 10\n");
                    num = 10;
                }

                printf("Números primos menores do que %d:\n\n", num);

                while (num >=  2){
                    //inicializa assumindo que o numero seja primo
                    primo = true;
                    for(i = 2; i < (num + 1) / 2 ; i++){
                        if (num % i == 0){
                            primo = false;
                        }
                    }
                    //imprime na tela, se o numero for primo
                    if (primo){
                        printf("%d. %d\n", index, num);
                        index++;
                    }
                    num--;
                }

                break;
            case 's':
                continue;
            default:
                printf("\n\nErro, opção '%c' não encontrada.\n\n\n");
                continue;
        }
        scanf("%c", &decisao);
    }
    return 0;
}
