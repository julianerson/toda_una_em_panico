import os
from InquirerPy import inquirer
from calculo import calculo
from sympy.parsing.sympy_parser import parse_expr, standard_transformations, implicit_multiplication_application
import ctypes
from time import sleep as mimir

#acima temos as bibliotecas do codigo

transformations = standard_transformations + (implicit_multiplication_application,)#isso aqui faz variaveis como 2x serem possiveis

calc = calculo()

def informacoes():#informaçoes
     print('''calculos:
      para somas + (ex: 1+1=2)
      para subtraçao - (ex: 1-2= -1)
      para divisao / (ex: 2:2 =1)
      multiplicaçao * (ex: 2*2=4)
      para potencia ^ (ex: 3^2 = 9)
estamos em atualizaçoes desculpe''')

while True:#aqui onde o user começa a ver
     AGUI = inquirer.select(
            message='vamos aos calculos',
            choices=['sair','info','integracao indefinida', 'integraçao definida','calculadoraC']
            ).execute()#menu principal
     if 'sair' in AGUI:#sai
          break
     elif 'info' in AGUI:#da as informaçoes basicas
          informacoes()
          continue
     elif 'integracao indefinida' in AGUI:
          calc.integraçoes_indefinidas()
          print('otimo, temos mais contas otaro')
          continue
     elif 'integraçao definida' in AGUI:
          calc.integraçoes_definidas()
          continue
     elif 'calculadoraC' in AGUI:
          mom = inquirer.select(#escolhe o comando para c
               message='o que vc quer?',
               choices=["loop","matrizes","determinantes","matriz-multiplicada","cramer"]
               ).execute()#menu principal
          if os.name == "posix":          
               oioi = os.path.abspath("calculadora.so")
          if os.name == "nt":          
               oioi = os.path.abspath("calculadora.dll")
          teste = ctypes.CDLL(oioi)
          print("iniciando")
          print("\n"*1000)
          mimir(3)
          print("""dica:
                calculos aqui sao diferentes
                para potencia= pow(numero,expoente)
                raiz quadrada=sqrt(x)
                para cosseno = cos(x)
                para tangente = tan(x)
                log natural = log(x)
                log de 10 = log10(x)
                pi = p""")
          mimir(5)
          if "loop" in mom:
               print("iniciando...")
               mimir(2)
               teste.somatorio()
          elif "matrizes" in mom:
               print("iniciando...")
               mimir(2)
               teste.soma_matriz()
          elif "determinantes" in mom:
               print("iniciando...")
               mimir(2)
               teste.determinantes()
          elif "matriz-multiplicada" in mom:
               print("iniciando...")
               mimir(2)
               teste.matrizes_multiplicadas()
          elif "cramer" in mom:
               print("iniciando...")
               mimir(2)
               teste.crack()
          del teste
          continue
