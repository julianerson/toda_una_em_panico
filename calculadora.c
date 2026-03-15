#include <stdio.h>
#include <string.h>
#include "tinyexpr.h"

int somatorio(){//funçao somatorio
    double i = 0;//diz o i
    printf("diga o i\n");
    scanf(" %lf", &i);
    getchar(); // consome o '\n' que sobrou

    int repeti = 0;
    printf("diga quanto isso vai repetir\n");
    scanf(" %d", &repeti);
    getchar();

    char formula[100];
    printf("diga a formula pfv\n");
    fgets(formula, sizeof(formula), stdin);//pega a formula
    formula[strcspn(formula, "\n")] = 0; // ve o indice de onde esta o /n que o fget deixa e remove o '\n'

    double resultado = 0;//sera util, aquieta o rabo

    for (int reto = 0; reto < repeti; reto++){//aqui e aonde as coisas começam
        
        te_variable vars[] = { {"i", &i} };//usa a biblioteca tinyexpr para saber quais sao as variaveis da formula, no caso e limitado apenas ao i

        int err;
        te_expr *expr = te_compile(formula, vars, 1, &err);//aqui aonde ele le a formula,temos: formula, variaveis, quantas variaveis, e os erros na formula

        if (expr) {//se a formula esta escrito corretamente
            resultado += te_eval(expr);//valida a expreçao(calcula) da linha 28, e soma ao resutado
            te_free(expr);//zera a expreçao para poder refazer as contas
            i++;//reintera o i
        } else {
            printf("Erro na posição %d\n", err);//se der erro na sua formula
        }
    }
    printf("resultado e: %f\n",resultado);//ta ai
    return 0;
}

int main() {//a GUI do codigo, sim ela e uma bosta... ainda...
    char escolha[20];//escolha
    printf("voce quer algo mais bruto ne? bem temos a soluçao, dia o que você quer?\n");
    printf(" temos: somatorio,\n");//escolhas
    scanf(" %19s", escolha);
    if(strcmp(escolha,"somatorio")==0){
        somatorio();
    }else{
        printf("nao sei ler isso, nao sou uma IA retardado\n");//mensagem carinhosa para o user
    }
}
