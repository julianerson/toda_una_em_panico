from InquirerPy import inquirer
from calculo import calculo
from sympy.parsing.sympy_parser import parse_expr, standard_transformations, implicit_multiplication_application
#acima temos as bibliotecas do codigo

transformations = standard_transformations + (implicit_multiplication_application,)#isso aqui faz variaveis como 2x serem possiveis

calc = calculo()

def informacoes():#informaçoes
     print('''calculos:
      para somas + (ex: 1+1=2)
      para subtraçao - (ex: 1-2= -1)
      para divisao / (ex: 2:2 =1)
      multiplicaçao * (ex: 2*2=4)
      para potencia ? (ex: 3?2 = 9)
estamos em atualizaçoes desculpe''')

while True:#aqui onde o user começa a ver
     AGUI = inquirer.select(
            message='vamos aos calculos',
            choices=['sair','info','integracao indefinida', 'integraçao definida']
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