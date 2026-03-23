//mensagem para o programador, LEIA CADA COMENTARIO, eles são o unico documentario aqui
#include <stdio.h>
#include <string.h>
#include "tinyexpr.h"
#include <stdlib.h>

// Verifica se é Windows (32 ou 64 bits)
#if defined(_WIN32) || defined(_WIN64)
    #define OS_NAME "Windows"
    #include <windows.h> // Biblioteca específica do Windows

// Verifica se é Linux ou Unix
#elif defined(__unix__) || defined(__unix) || defined(__linux__)
    #define OS_NAME "unixlike"
    #include <unistd.h>

#else//caso nao soubermos o os
    #define OS_NAME "Desconhecido"
#endif

const double p = 3.141593;//pi e constante em TODO O CODIGO, e e uma variavel externa

void limpar_tela(){
    if(strcmp(OS_NAME,"Windows")==0){//comando de limpeza
        system("cls");
    }else if(strcmp(OS_NAME,"unixlike")==0){
        system("clear");
    }
}

int soma_matriz(){//isso aqui sao as somas de matrizes
    int l;//linhas
    int c;//colunas
    char oito[10];
    printf("soma ou subtracao?\n");
    scanf(" %s",&oito);
    printf("diga quantas linhas tem as matrizes\n");
    scanf(" %d",&l);
    printf("diga quantas colunas tem as matrizes\n");
    scanf(" %d",&c);
    printf("diga agora sobre a primeira matriz\n");
    int matriz1[l][c];
    int matriz2[l][c];
    int matriz3[l][c];//resultado da somas das matrizes 1 e 2
    for(int j = 0; j<l;j++){//cria a matriz 1
        for(int i = 0; i < c; i++){//isso muda as colunas, e apos ir em todas as colunas possiveis muda de linha
            printf("matriz1 [%d][%d]\n",j,i);//j=linha atual e i=coluna atual
            scanf(" %d",&matriz1[j][i]);
            limpar_tela();
        }
    }
    limpar_tela();
    printf("\nvamos a matriz2\n");
    for(int j = 0; j<l;j++){//cra a matriz 2
        for(int i = 0; i < c; i++){
            printf("matriz2 [%d][%d]\n",j,i);
            scanf(" %d",&matriz2[j][i]);//coloca os dados
            limpar_tela();
        }
    }
    printf("\nmatriz1=\n");//printa a matriz 1
    for(int j = 0; j<l;j++){
        for(int i = 0; i < c; i++){
            printf("(%d)\0",matriz1[j][i]);
        }
        printf("\n");
    }
    printf("\nmatriz2=\n");
    for(int j = 0; j<c;j++){
        for(int i = 0; i < l; i++){
            printf("(%d)\0",matriz2[j][i]);
        }
        printf("\n");
    }
    for(int j = 0; j<l;j++){//calcula as matrizes e faz a matriz3(resultado)
        for(int i = 0; i < c; i++){
            matriz3[j][i] = 0;
            if(strcmp(oito,"soma")==0){//verifica se e soma ou subtraçao
                matriz3[j][i] = matriz1[j][i] + matriz2[j][i];
            }else if(strcmp(oito,"subtracao")==0){
                matriz3[j][i] = matriz1[j][i] - matriz2[j][i];
            }
        }
    }
    printf("\nmatriz3=\n");
    for(int j = 0; j<c;j++){
        for(int i = 0; i < l; i++){
            printf("(%d)\0",matriz3[j][i]);
        }
        printf("\n");
    }
}

int somatorio(){//funçao somatorio
    char comando[20];
    double i = 0;//diz o i

    printf("você quer somatorio,produtorio\n");
    scanf(" %s",&comando);
    limpar_tela();

    printf("\ndiga o i\n");
    printf(">");
    scanf(" %lf", &i);
    getchar(); // consome o '\n' que sobrou

    limpar_tela();

    int repeti = 0;
    printf("\ndiga quanto isso vai repetir\n");
    scanf(" %d", &repeti);
    printf(">");
    getchar();

    limpar_tela();

    char formula[100];
    printf("\ndiga a formula pfv\n");
    printf(">");
    fgets(formula, sizeof(formula), stdin);//pega a formula
    formula[strcspn(formula, "\n")] = 0; // ve o indice de onde esta o /n que o fget deixa e remove o '\n'

    double resultado;//sera util, aquieta o rabo
    if(strcmp(comando,"somatorio")==0){
       resultado = 0;//ve se e somatorio
    }else if(strcmp(comando,"produtorio")==0){
       resultado = 1;//ve se a conta e produtorio
    }

    for (int reto = 0; reto < repeti; reto++){//aqui e aonde as coisas começam
        
        te_variable vars[] = { {"i", &i}, {"p", &p} };//usa a biblioteca tinyexpr para saber quais sao as variaveis da formula, no caso e limitado apenas ao i

        int err;
        te_expr *expr = te_compile(formula, vars, 2, &err);//aqui aonde ele le a formula,temos: formula, variaveis, quantas variaveis, e os erros na formula

        if (expr) {//se a formula esta escrito corretamente
            if(strcmp(comando,"somatorio")==0){
               resultado += te_eval(expr);//valida a expreçao(calcula) da linha 28, e soma ao resutado
            }else if(strcmp(comando,"produtorio")==0){
               resultado =resultado * te_eval(expr);//valida a expreçao(calcula) da linha 28, e multiplica ao resutado
            }
            te_free(expr);//zera a expreçao para poder refazer as contas
            i++;//reintera o i
        } else {
            printf("Erro na posição %d\n", err);//se der erro na sua formula
        }
    }
    printf("\nresultado e: %f\n",resultado);//ta ai
    return 0;
}

int main() {//a GUI do codigo, sim ela e uma bosta... ainda...
    char escolha[20];//escolha
    printf("voce quer algo mais bruto ne? bem temos a soluçao, dia o que você quer?\n");
    printf(" temos: loop,matrizes\n");//escolhas
    printf(">");
    scanf(" %19s", escolha);
    if(strcmp(escolha,"loop")==0){
        somatorio();
    }else if(strcmp(escolha,"matrizes")==0){
        soma_matriz();
    }else{
        printf("nao sei ler isso, nao sou uma IA retardado\n");//mensagem carinhosa para o user
    }
}