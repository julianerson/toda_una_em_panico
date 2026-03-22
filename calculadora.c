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


int soma_matriz(){//isso aqui sao as somas de matrizes
    int l;//linhas
    int c;//colunas
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
            if(strcmp(OS_NAME,"Windows")==0){//o if e else if limpam a tela
                system("cls");
            }else if(strcmp(OS_NAME,"unixlike")==0){
                system("clear");
            }
        }
    }
    if(strcmp(OS_NAME,"Windows")==0){//comando de limpeza
        system("cls");
    }else if(strcmp(OS_NAME,"unixlike")==0){
        system("clear");
    }

    printf("\nvamos a matriz2\n");
    for(int j = 0; j<l;j++){//cra a matriz 2
        for(int i = 0; i < c; i++){
            printf("matriz2 [%d][%d]\n",j,i);
            scanf(" %d",&matriz2[j][i]);//coloca os dados
            if(strcmp(OS_NAME,"Windows")==0){//o if e else if limpam a tela
                system("cls");
            }else if(strcmp(OS_NAME,"unixlike")==0){
                system("clear");
            }
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
    for(int j = 0; j<l;j++){
        for(int i = 0; i < c; i++){
            matriz3[j][i] = 0;
            matriz3[j][i] = matriz1[j][i] + matriz2[j][i];
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
    const double p = 3.141593;//fds #define
    double i = 0;//diz o i
    printf("\ndiga o i\n");
    printf(">");
    scanf(" %lf", &i);
    getchar(); // consome o '\n' que sobrou

    if(strcmp(OS_NAME,"Windows")==0){//o if e else if limpam a tela
        system("cls");
    }else if(strcmp(OS_NAME,"unixlike")==0){
        system("clear");
    }

    int repeti = 0;
    printf("\ndiga quanto isso vai repetir\n");
    scanf(" %d", &repeti);
    printf(">");
    getchar();

    char formula[100];
    printf("\ndiga a formula pfv\n");
    printf(">");
    fgets(formula, sizeof(formula), stdin);//pega a formula
    formula[strcspn(formula, "\n")] = 0; // ve o indice de onde esta o /n que o fget deixa e remove o '\n'

    if(strcmp(OS_NAME,"Windows")==0){//o if e else if limpam a tela
        system("cls");
    }else if(strcmp(OS_NAME,"unixlike")==0){
        system("clear");
    }

    double resultado = 0;//sera util, aquieta o rabo

    for (int reto = 0; reto < repeti; reto++){//aqui e aonde as coisas começam
        
        te_variable vars[] = { {"i", &i}, {"p", &p} };//usa a biblioteca tinyexpr para saber quais sao as variaveis da formula, no caso e limitado apenas ao i

        int err;
        te_expr *expr = te_compile(formula, vars, 2, &err);//aqui aonde ele le a formula,temos: formula, variaveis, quantas variaveis, e os erros na formula

        if (expr) {//se a formula esta escrito corretamente
            resultado += te_eval(expr);//valida a expreçao(calcula) da linha 28, e soma ao resutado
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
    printf(" temos: somatorio,soma_matrizes\n");//escolhas
    printf(">");
    scanf(" %19s", escolha);
    if(strcmp(escolha,"somatorio")==0){
        somatorio();
    }else if(strcmp(escolha,"soma_matrizes")==0){
        soma_matriz();
    }else{
        printf("nao sei ler isso, nao sou uma IA retardado\n");//mensagem carinhosa para o user
    }
}
