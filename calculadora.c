//mensagem para o programador, LEIA CADA COMENTARIO, eles são o unico documentario aqui
//---mensagem---//
//o que e isto: e uma calculadora projetada para estudantes de engenharia
//quem fez isso? https://www.youtube.com/watch?v=1tpIxo4vy80
//porque em C? este codigo deve ser eficiente e didatico, e a linguagem mais eficiene e assebly(mas claramente nao e didatica) e a mais didatica e python(0 eficiencia manos e manas e manes)
//obs: este codigo deve ser compilavel tanto para windows como linux, o resto foda-se

#include <stdio.h>
#include <string.h>
#include "tinyexpr.h"//importa a biblioteca responsavel pela tradução de formula, possivelmente sera util em utilizções futuras
#include <stdlib.h>
#include <time.h>

// Verifica se é Windows (32 ou 64 bits)
#if defined(_WIN32) || defined(_WIN64)
    #define OS_NAME "Windows"
    #include <windows.h> // Biblioteca específica do Windows

// Verifica se é Linux ou Unix
#elif defined(__unix__) || defined(__unix) || defined(__linux__)
    #define OS_NAME "unixlike"
    #include <unistd.h>

#else//caso nao soubermos o os
    #define OS_NAME "Desconhecido"//"e a galerinha do mac" foda-se eles, quase ninguem deles programa, eu espero
#endif

const double p = 3.141593;//pi e constante em TODO O CODIGO, e e uma variavel externa

void limpar_tela(){//nome do comando
    if(strcmp(OS_NAME,"Windows")==0){//comando de limpeza, tanto para windows quanto mac
        system("cls");
    }else if(strcmp(OS_NAME,"unixlike")==0){
        system("clear");
    }
}

void matrizes_multiplicadas(){
    limpar_tela();
    int l1,c1,l2,c2,i,j,resposta,k,fl,fc;//variaveis nescessarias para multiplicaçao
    printf("diga quantas linas da 1ºmatriz\n");//da o tamanho da matriz, não e muito elegante mas e o que temos
    scanf(" %d",&l1);
    printf("\nagora a 2 matriz\n");
    limpar_tela();
    printf("diga quantas colunas ha na 2º matriz\n");//da o tamanho da matriz, não e muito elegante mas e o que temos
    scanf(" %d",&c2);
    printf("diga quantas linhas da 2 matriz, e as colunas da 1\n");//da o tamanho da matriz, não e muito elegante mas e o que temos
    scanf(" %d",&l2);
    c1 = l2;
    int **matriz1 = (int**)malloc(c1*sizeof(int*));
    for(i=0;i<c1;i++){//o int de cima e esse de baixo criam uma matriz mais elegante
        matriz1[i]=(int*)malloc(l1*sizeof(int));
    }
    int **matriz2 = (int**)malloc(c2*sizeof(int*));//todos com esse int **matriz blablabla, são criações mais elegantes de matrizes prezando pela eficiencia do codigo, e sim e dificil mesmo
    for(i=0;i<c2;i++){//continuaçao do comentario a cima: todos que lerem essas partes vão se foder mesmo, desculpe programador, além de mim
        matriz2[i]=(int*)malloc(l2*sizeof(int));
    }
    int **matriz3 = (int**)malloc(c2*sizeof(int*));
    for(i=0;i<c2;i++){
        matriz3[i]=(int*)malloc(l1*sizeof(int));
    }
    for(i = 0; i<l1;i++){//da os valores a matriz 1
        for(j = 0; j < c1; j++){//isso muda as colunas, e apos ir em todas as colunas possiveis muda de linha
            fc = j+1;
            fl = 1+i;
            printf("matriz1 [%d][%d]\n",fl,fc);//j=linha atual e i=coluna atual
            scanf(" %d",&matriz1[i][j]);
            limpar_tela();
        }
    }for(j = 0; j<l2;j++){//da os valores a matriz 2
        for(i = 0; i < c2; i++){//isso muda as colunas, e apos ir em todas as colunas possiveis muda de linha
            printf("matriz2 [%d][%d]\n",j,i);//j=linha atual e i=coluna atual
            scanf(" %d",&matriz2[j][i]);
            limpar_tela();
        }
    }
    for(i = 0; i<l1;i++)//R.I.P. minha sanidade
    {
        for(j = 0; j < c2; j++)
        {
            matriz3[i][j] = 0;//zera a parte que iremos colocar na matriz
            for(k = 0;k<l2;k++)//loop que usa o recurso de que sempre a coluna da matriz 1 sera igual a linha da matriz 1
            {//tornando possivel o calculo
                matriz3[i][j]+=matriz1[i][k]*matriz2[k][j];//calcula
            }
        }
    }
    printf("\nmatriz1=\n");//printa a matriz 1
    for(i = 0; i<l1;i++){
        for(j = 0; j < c1; j++){
            printf("(%d)\0",matriz1[i][j]);
        }
        printf("\n");
    }
    printf("\nmatriz2=\n");
    for(i = 0; i<l2;i++){
        for(j = 0; j < c2; j++){
            printf("(%d)\0",matriz2[i][j]);
        }
        printf("\n");
    }
    printf("\no resultado e:\n");
    for(i = 0; i<l1;i++){
        for(j = 0; j < c2; j++){
            printf("(%d)\0",matriz3[i][j]);
        }
        printf("\n");
    }
}

void determinantes(){
    limpar_tela();
    int l,i,j,col,fl,fc,resposta,solucaoP,linhaP,solucaoS,linhaS;//variaveis nescessarias para a determinantes
    solucaoP = 0;//aqui nos damos aos valores as variaveis para que nao seja alterado o calculo
    solucaoS = 0;
    linhaP = 1;
    linhaS = 1;
    printf("diga o tamanho");//da o tamanho da matriz, não e muito elegante mas e o que temos
    scanf(" %d",&l);
    int **matriz = (int**)malloc(l*sizeof(int*));
    for(i=0;i<l;i++){//o int de cima e esse de baixo criam uma matriz mais elegante
        matriz[i]=(int*)malloc(l*sizeof(l));
    }
    int **matrizp = (int**)malloc(l*sizeof(int*));
    for(i=0;i<l;i++){
        matrizp[i]=(int*)malloc(l*sizeof(l));
    }
    int **matrizs = (int**)malloc(l*sizeof(int*));
    for(i=0;i<l;i++){
        matrizs[i]=(int*)malloc(l*sizeof(l));
    }
    for(i = 0; i<l;i++){//cria a matriz 1
        for(j = 0; j < l; j++){//isso muda as colunas, e apos ir em todas as colunas possiveis muda de linha
            fl = i+1;
            fc = j+1;
            printf("matriz1 [%d][%d]\n",fl,fc);//j=linha atual e i=coluna atual
            scanf(" %d",&matriz[i][j]);
            limpar_tela();
        }
    }
    for(j = 0; j<l;j++){//valor para a matrizp
        for(i =  0; i < l; i++){
            col = (j+i)%l;//gambiarra matematica que da coordenadas para que a criaçao dessas matrizes seja possivel
            matrizp[i][j]=matriz[j][col];
        }
    }
    for(j = 0; j<l;j++){
        for(i = 0; i < l; i++){//valor da matrizs
            col = (l-1) - ((j+i)%l);//gambiarra 2x
            matrizs[i][j]=matriz[j][col];
        }
    }
    for(j = 0; j<l;j++){//aqui a matrizp e calculada para que funcione igual o calculo da diagonal principal
        for(i = 0; i < l; i++){
            linhaP = linhaP * matrizp[j][i];
        };
        solucaoP += linhaP;
        linhaP = 1;
    }
    for(j = 0; j<l;j++){//mesmo que o loop acima
        for(i = 0; i < l; i++){
            linhaS = linhaS * matrizs[j][i];
        };
        solucaoS += linhaS;
        linhaS = 1;
    }
    printf("\na matriz e:\n");
    for(i = 0; i<l;i++){//matriz
        for(j=0;j<l;j++){
            fc = j+1;
            fl = i+1;
            printf("(%d)",matriz[i][j]);
        }
        printf("\n");
    }
    free(matriz);//libera os dados das matrizes, nao parece muto util, mas e um bom habito
    free(matrizp);
    free(matrizs);
    resposta = solucaoP - solucaoS;//calculo das duas diagonais
    printf("\ne sua determinante e %d\n",resposta);
}

void soma_matriz(){//isso aqui sao as somas de matrizes
    limpar_tela();
    int j;
    int i;
    int l;//linhas
    int c;//colunas
    int fc,fl;//esses serao os valores que os users verao
    char oito[10];
    printf("soma ou subtracao?\n");
    scanf(" %s",&oito);
    printf("diga quantas linhas tem as matrizes\n");
    scanf(" %d",&l);
    printf("diga quantas colunas tem as matrizes\n");
    scanf(" %d",&c);
    printf("diga agora sobre a primeira matriz\n");
    int **matriz1 = (int**)malloc(c*sizeof(int*));
    for(i=0;i<c;i++){//o int de cima e esse de baixo criam uma matriz mais elegante
        matriz1[i]=(int*)malloc(l*sizeof(int));
    }
    int **matriz2 = (int**)malloc(c*sizeof(int*));//todos com esse int **matriz blablabla, são criações mais elegantes de matrizes prezando pela eficiencia do codigo, e sim e dificil mesmo
    for(i=0;i<c;i++){//continuaçao do comentario a cima: todos que lerem essas partes vão se foder mesmo, desculpe programador, além de mim
        matriz2[i]=(int*)malloc(l*sizeof(int));
    }
    int **matriz3 = (int**)malloc(c*sizeof(int*));
    for(i=0;i<c;i++){
        matriz3[i]=(int*)malloc(l*sizeof(int));
    }
    for(int i = 0; i<l;i++){//cria a matriz 1
        for(int j = 0; j < c; j++){//isso muda as colunas, e apos ir em todas as colunas possiveis muda de linha
            fl = i+1;
            fc = j+1;
            printf("matriz1 [%d][%d]\n",fl,fc);//j=linha atual e i=coluna atual
            scanf(" %d",&matriz1[i][j]);
            limpar_tela();
        }
    }
    printf("\nvamos a matriz2\n");
    for(int i = 0; i<l;i++){//cria a matriz 2
        for(int j = 0; j < c; j++){
            fl = i+1;
            fc = j+1;
            printf("matriz2 [%d][%d]\n",fl,fc);
            scanf(" %d",&matriz2[i][j]);//coloca os dados
            limpar_tela();
        }
    }
    printf("\nmatriz1=\n");//printa a matriz 1
    for(int i = 0; i<l;i++){
        for(int j = 0; j < c; j++){
            printf("(%d)\0",matriz1[i][j]);
        }
        printf("\n");
    }
    printf("\nmatriz2=\n");//printa a matriz 2
    for(int i = 0; i<l;i++){
        for(int j = 0; j < c; j++){
            printf("(%d)\0",matriz2[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i<l;i++){//calcula as matrizes e faz a matriz3(resultado)
        for(int j = 0; j < c; j++){
            matriz3[i][j] = 0;
            if(strcmp(oito,"soma")==0){//verifica se e soma ou subtraçao
                matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
            }else if(strcmp(oito,"subtracao")==0){
                matriz3[i][j] = matriz1[i][j] - matriz2[i][j];
            }
        }
    }
    printf("\nmatriz3=\n");
    for(i = 0; i<l;i++){
        for(j = 0; j < c; j++){
            printf("(%d)\0",matriz3[i][j]);
        }
        printf("\n");
    }
}

int somatorio(){//funçao somatorio
    limpar_tela();
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

void crack(){
    int t,det,col/*coluna*/,lin/*linha*/,cam/*camadas*/,g;
    printf("diga quantas variaveis tem no sistema linear\n");
    scanf(" %d",&t);
    det = t+1;

    //mesma logica da funçao determinantes()
    int **matrizp = (int**)malloc(t*sizeof(int*));
    for(col=0;col<t;col++){
        matrizp[col]=(int*)malloc(t*sizeof(int));
    }
    int **matrizs = (int**)malloc(t*sizeof(int*));
    for(col=0;col<t;col++){
        matrizs[col]=(int*)malloc(col*sizeof(int));
    }
    //mesma logica da funçao determinantes()
    
    int *determinantes = (int*)malloc(det*sizeof(int));//respostas das determinantes
    int *variaveis =(int*)malloc(t*sizeof(int));//respostas das formulas(sim as respostas das formulas ficam em uma lista propria)
    double *respostas = (double*)malloc(t*sizeof(double));//respostas das variaveis mesmo
    int **matriz = (int**)malloc(t*sizeof(int*));//formulas de verdade

    //matriz normal
    for(col=0;col<t;col++){
        matriz[col]=(int*)malloc(t*sizeof(int));
    }
    //matriz normal

    //matriz com variaveis
    int ***tudo = (int***)malloc(t * sizeof(int**));//cria linha 1
    for (int lin = 0; lin < t; lin++) {
        tudo[lin] = (int**)malloc(t * sizeof(int*));//faz matriz bidimensional
        for (int col = 0; col < t; col++) {
            tudo[lin][col] = (int*)malloc(t * sizeof(int));//3 dimensoes amor
        }
    }
    //matriz com variaveis

    printf("agora fale os numeros das formulas em ordem\n");
    for(lin=0;lin<t;lin++){
        for (col = 0; col < t; col++){
            printf("valor na formula %d posiçao %d \n",lin+1,col+1);
            scanf(" %d",&g);
            matriz[lin][col]=g;
        }
        limpar_tela();
    }

    for (lin=0;lin<t;lin++)
    {
        printf("diga a resposta da formula %d\n",lin+1);
        scanf(" %d",&g);
        variaveis[lin]=g;
        limpar_tela();
    }

    //valores matrizes
    for (cam = 0; cam < t; cam++){
        for (lin = 0; lin < t; lin++){
            for (col = 0; col < t; col++){
                if(cam==col){
                    tudo[cam][lin][col]=variaveis[lin];
                }else{
                    tudo[cam][lin][col]=matriz[lin][col];
                }
            }
        }
    }
    //valores matrizes

    int resposta,solucaoP,linhaP,solucaoS,linhaS;//variaveis nescessarias para a determinantes
    
    for (cam = 0; cam < det; cam++){
        solucaoP = 0;//aqui nos damos aos valores as variaveis para que nao seja alterado o calculo
        solucaoS = 0;
        linhaP = 1;
        linhaS = 1;
        if (cam!=t){
        
            for(lin = 0; lin < t; lin++){//valor para a matrizp
                for(col = 0; col < t; col++){
                    g = (col+lin)%t;//gambiarra matematica que da coordenadas para que a criaçao dessas matrizes seja possivel
                    matrizp[lin][col]=tudo[cam][col][g];
                }
            }
            for(lin = 0; lin < t; lin++){
                for(col = 0; col < t; col++){//valor da matrizs
                    g = (t-1) - ((col+lin)%t);//gambiarra 2x
                    matrizs[lin][col]=tudo[cam][col][g];
                }
            }
            for(lin = 0; lin < t; lin++){//aqui a matrizp e calculada para que funcione igual o calculo da diagonal principal
                for(col = 0; col < t; col++){
                    linhaP = linhaP * matrizp[lin][col];
                };
                solucaoP += linhaP;
                linhaP = 1;
            }
            for(lin = 0; lin < t; lin++){//mesmo que o loop acima
                for(col = 0; col < t; col++){
                    linhaS = linhaS * matrizs[lin][col];
                };
                solucaoS += linhaS;
                linhaS = 1;
            }
            printf("(%d)(%d)%d\n",solucaoP, solucaoS,cam+1);
            determinantes[cam] = solucaoP - solucaoS;
        }else{
            for(lin = 0; lin < t; lin++){//valor para a matrizp
                for(col = 0; col < t; col++){
                    g = (col+lin)%t;//gambiarra matematica que da coordenadas para que a criaçao dessas matrizes seja possivel
                    matrizp[lin][col]=matriz[col][g];
                }
            }
            for(lin = 0; lin < t; lin++){
                for(col = 0; col < t; col++){//valor da matrizs
                    g = (t-1) - ((col+lin)%t);//gambiarra 2x
                    matrizs[lin][col]=matriz[col][g];
                }
            }
            for(lin = 0; lin < t; lin++){//aqui a matrizp e calculada para que funcione igual o calculo da diagonal principal
                for(col = 0; col < t; col++){
                    linhaP = linhaP * matrizp[lin][col];
                };
                solucaoP += linhaP;
                linhaP = 1;
            }
            for(lin = 0; lin < t; lin++){//mesmo que o loop acima
                for(col = 0; col < t; col++){
                    linhaS = linhaS * matrizs[lin][col];
                };
                solucaoS += linhaS;
                linhaS = 1;
            }
            printf("matriz normal(%d)(%d)%d\n",solucaoP, solucaoS,cam+1);
            determinantes[cam] = solucaoP - solucaoS;
        }
    }
    if(determinantes[t]=0){
        printf("cramer n resolve isso");
    }else{
        for (g=0;g<t;g++)
        {
            respostas[g]=(double)determinantes[g]/determinantes[t];
            printf("a resposta da variavel %d e (%lf)\n",g+1,respostas[g]);
        }
    }

    free(matrizp);
    free(matrizs);
    free(matriz);
    free(tudo);
    free(respostas);
    free(variaveis);
    free(determinantes);
}