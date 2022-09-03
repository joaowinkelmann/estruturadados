//Exercício 6
//Calculadora em linha de comando

// - Variáveis
// - Operadores 
// - Entrada e saída de dados
// - Comandos condicionais 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL,"");
    double x, y;
    char op;
    printf("Seja bem vindo a calculadora em CLI\n");

    //recebe o primeiro valor
    printf("Para começar, insira o primeiro número como parâmetro \n");
    scanf("%lf", &x);

    //recebe o operador
    printf("Entre com o operador desejado: \n\n+ -> Adição\n- -> Subtração\n* -> Multiplicação\n/ -> Divisão\ne -> Exponencial (x^y)\n");
    scanf("%s", &op);

    //recebe o segundo valor
    printf("Agora, entre com o segundo valor a ser analisado\n");
    scanf("%lf", &y);

    // Debug para ver os valores
    // printf("%lf %c %lf", x, op, y);

    switch (op){
        case '+':
            printf("\nResultado: %.2lf (%.2lf + %.2lf)", (x+y), x, y);
            break;
        case '-':
            printf("\nResultado: %.2lf (%.2lf - %.2lf)", (x-y), x, y);
            break;
        case '*':
            printf("\nResultado: %.2lf (%.2lf * %.2lf)", (x*y), x, y);
            break;
        case '/':
            if(y == 0){
                printf("Erro: Impossível dividir por zero (%.2lf/%.2lf)\n", x, y);
                exit(1);
            }
            printf("\nResultado: %.2lf (%.2lf / %.2lf)", (x/y), x, y);
            break;
        case 'e':
            printf("\nResultado: %.2lf (%.2lf ^ %.2lf)", pow(x, y), x, y);
            break;
        default:
            printf("Erro: O operador não é válido.");
            exit(1);
    }    
}