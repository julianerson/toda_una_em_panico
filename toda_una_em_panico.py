import scipy
from InquirerPy import inquirer
import sympy
from sympy.parsing.sympy_parser import parse_expr, standard_transformations, implicit_multiplication_application
#acima temos as bibliotecas do codigo

transformations = standard_transformations + (implicit_multiplication_application,)#isso aqui faz variaveis como 2x serem possiveis

def informacoes():#informaçoes
     print('''calculos:
      para somas + (ex: 1+1=2)
      para subtraçao - (ex: 1-2= -1)
      para divisao / (ex: 2:2 =1)
      multiplicaçao * (ex: 2*2=4)
      para potencia ? (ex: 3?2 = 9)
estamos em atualizaçoes desculpe''')

class calculo:#noçoes de calculo
     def integraçoes_definidas(self):#integraçao definida
          print('seja bem vindo, vamos fazer integraçoes simples definidas')
          denifiçoes1 = int(input('diga o inicio de onde vamos integrar'))#a parte do inicio da area que vamos calcular
          denifiçoes2 = int(input('otimo, diga o fim de onde vamos integrar'))#a parte final
          varia = sympy.symbols(input('diga as variaveis e as separe com espaço'))#aqui ode encaixa as variaveis
          formulastr = input('printe sua formula').replace('?', '**')#aqui e colocado a formula
          formulas = parse_expr(formulastr, transformations=transformations)#aqui a formula e traduzida para o sympy
          integral = sympy.integrate(formulas,(varia, denifiçoes1, denifiçoes2))#temos a integral em si
          print(f'a sua integral de {denifiçoes1} ate {denifiçoes2} vai gerar {integral}')#seu resultado

     def integraçoes_indefinidas(self):#quase a mesma bosta da integral definida
          print('ola bem vindo as integrais indefinidas, por enquanto de variavels temos so x vamos atualizar')#preciso explicar?
          varia = sympy.symbols(input('diga as variaveis e as separe com espaço'))#variaveis
          formulastr = input('printe sua formula').replace('?', '**')#formula
          formulas = parse_expr(formulastr, transformations=transformations)#traduçao da formula para o sympy
          integral01 = sympy.integrate(formulas, varia)#aqui fazemos as integrais
          print(f'a sua formula tem a seguinte integral {integral01} + C')#vc realmente acha que iria esquecer do C? vc esta quase certo

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
          calculo.integraçoes_indefinidas()
          print('otimo, temos mais contas otaro')
          continue
     elif 'integraçao definida' in AGUI:
          calculo.integraçoes_definidas()
          continue