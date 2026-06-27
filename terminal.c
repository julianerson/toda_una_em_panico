#include <stdlib.h>
#include <stdio.h>

#include <string.h>
// Verifica se é Windows (32 ou 64 bits)
#if defined(_WIN32) || defined(_WIN64)
    #define OS_NOME "Windows"
    #include <windows.h> // Biblioteca específica do Windows
    #include <conio.h>//getch nosmal

// Verifica se é Linux ou Unix
#elif defined(__unix__) || defined(__unix) || defined(__linux__)
    #define OS_NOME "unixlike"
    #include <unistd.h>

    #include <termios.h>//isto e uma biblioteca de teclado linux ou mac
    #include <unistd.h>//biblioteca linux

    int _getch(void) {//recria a funçao _getch
        struct termios oldattr, newattr;//cria duas variaveis, uma com as configuraçãoes atuais de teclado
        int ch;
        tcgetattr(STDIN_FILENO, &oldattr);//salva as config de teclado tual
        newattr = oldattr;
        newattr.c_lflag &= ~(ICANON | ECHO); // Desativa o Enter e o eco do caractere
        tcsetattr(STDIN_FILENO, TCSANOW, &newattr);//aplica essas duas novas config
        ch = getchar();//pega a tecla
        tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); // Restaura a configuração original
        return ch;
    }

#else//caso nao soubermos o os
    #define OS_NOME "Desconhecido"
#endif





void limpar_tela(){//funçao de limpeza
    if(strcmp(OS_NOME,"Windows")==0){
        system("cls");
    }else if(strcmp(OS_NOME,"unixlike")==0){
        system("clear");
    }
}
char* listao(char **vai){
    int tecla;
    int varea = 0;
    int total = 0;

    // 1. Descobre o tamanho total do menu de forma segura antes do loop
    while(vai[total] != NULL) {
        total++;
    }

    while(1) {
        limpar_tela();
        
        // 2. Desenha o menu atualizado na tela
        for (int i = 1; i < total; i++) {
            if (i==1){
                printf("\x1b[0m%s\n", vai[0]);
            }
            if (i == varea) {
                printf("\x1b[32m=> %s\n", vai[i]); // Item selecionado (Verde)
            } else {
                printf("\x1b[0m%s\n", vai[i]);     // Itens normais
            }
        }
        printf("\x1b[0m"); // Reseta as cores do terminal

        tecla = _getch();

        // --- TRATAMENTO PARA WINDOWS ---
        #ifdef _WIN32
        if (tecla == 224) { 
            tecla = _getch(); 
            if (tecla == 72) {        // Seta para CIMA
                varea--;
            } else if (tecla == 80) { // Seta para BAIXO
                varea++;
            }
        }
        // --- TRATAMENTO PARA LINUX ---
        #else
        if (tecla == 27) { 
            int proximo1 = _getch(); 
            int proximo2 = _getch(); 
            if (proximo1 == 91 || proximo1 == '[') {
                if (proximo2 == 65 || proximo2 == 'A') {      // Seta para CIMA
                    varea--;
                } else if (proximo2 == 66 || proximo2 == 'B') { // Seta para BAIXO
                    varea++;
                }
            }
        }
        #endif

        // Condição de saída (Enter)
        if (tecla == 13 || tecla == 10) {
            return vai[varea];
        }

        // 3. TRAVAS DE SEGURANÇA: Evita que o índice saia do vetor (Causa do SegFault)
        if (varea >= total) {
            varea = 0;         // Volta para o topo se passar do fim
        }
        if (varea < 0) {
            varea = total - 1; // Vai para o fim se passar do topo
        }
    }
}
