# toda_una_em_panico

toda una esta em panico, entao aqui a soluçao, obvio que nao vcs tao fudidos, mas isso pode ajudar, no momento temos integrais simples, determinantes, somatorio e produtorio

# bugs
1. a multiplicaçao de matrizes buga se as matrizes mumtiplicadas nao tiverem o mesmo tamanho

# manual do programador 2

eu ainda nao achei uma solução para a adição de bibliotecas, o que me faz recomentar FORTEMENTE que voce compile o codigo, e esses sao os comandos para compilaçao

1. gcc -shared -fPIC  -o calculadora.so calculadora.c tinyexpr.c -lm / para linux

2. x86_64-w64-mingw32-gcc -shared -fPIC calculadora.c tinyexpr.c -o calculadora.dll -lm / para windows 
 
-shared -fPIC / transforma o codiogo em c para biblioteca, terirando a nescessidade de uma funçao main

# para o programador:
esse codigo preza pela facilidade do programador, e do user, e lembre-se, o codigo nao precisa ser algo complexo, mas sim algo facil de ler e funcional, mantendo à facilidade da manutençao para que qualquer dev tanto experiente quanto inexperiente sejám capazes de mexer.
também não se esqueça do user que deve ter uma facilidade em sua manutenção

bem nos temos uma integração com c para calculos mais brutos

# bibliotecas nescesarias:
sympy, Inquirerpy, scipy
