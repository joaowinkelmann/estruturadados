//Exercício 7
//    DESCRIÇÃO
// - While
// - For
// - Do/while
// - break e continue

#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "");
    int i, j;
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
                printf("Sequência de fibonacci selecionada.\nEntre com um número para ser o limite da operação:\n");
                scanf("%d", &maxFib);

                do{
                    printf("%d. %d\n", (i+1), z);
                    z = x + y;
                    x = y;
                    y = z;
                    i++;
                } while (maxFib >= z);

                break;
            case 'p':
                break;
            case 's':
                continue;
            default:
                printf("\n\nErro, opção '%c' não encontrada.\n\n\n");
                continue;
        }

    
        printf("Escolha o que deseja fazer:\n");
        scanf("%c", &decisao);
    }
    
}
