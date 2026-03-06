import scipy
import InquirerPy
import sympy
from sympy.parsing.sympy_parser import parse_expr, standard_transformations, implicit_multiplication_application

transformations = standard_transformations + (implicit_multiplication_application,)

print('''para somas + (ex: 1+1=2)
      para subtraçao - (ex: 1-2= -1)
      para divisao / (ex: 2:2 =1)
      multiplicaçao * (ex: 2*2=4)
      para potencia ? (ex: 3?2 = 9)''')

def integraçoes_indefinidas():
    print('ola bem vindo as integrais indefinidas, por enquanto de variavels temos so x vamos atualizar')
    varia = sympy.symbols(input('diga as variaveis e as separe com espaço'))
    formulastr = input('printe sua formula').replace('?', '**')
    formulas = parse_expr(formulastr, transformations=transformations)
    integral01 = sympy.integrate(formulas, varia)
    print(f'a sua formula tem a seguinte integral {integral01}')

integraçoes_indefinidas()