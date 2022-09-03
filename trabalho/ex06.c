//Calculadora em linha de comando

// - Variáveis
// - Operadores
// - I/O de dados
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
    printf("Entre com o operador desejado: \n\n+ -> Adição\n- -> Subtração\n* -> Multiplicação\n/ -> Divisão\n(p ou e) -> Exponencial (x^y)\n");
    scanf("%s", &op);

    //recebe o segundo valor
    printf("Agora, entre com o segundo valor a ser analisado\n");
    scanf("%lf", &y);

    printf("%lf %c %lf", x, op, y);


}