# licença GNU GPL v3
# toda_una_em_panico | a calculadora para engenheiros novatos desesperados
# Copyright (C) 2026 Nilson
# Contato: nilson.m.b.abreu@gmail.com
#
# Este programa é software livre: você pode redistribuí-lo e/ou modificá-lo
# sob os termos da GNU General Public License publicada pela Free Software Foundation,
# na versão 3 da Licença, ou (a seu critério) qualquer versão posterior.
#
# Este programa é distribuído na esperança de que seja útil,
# mas SEM NENHUMA GARANTIA; sem mesmo a garantia implícita de
# COMERCIALIZAÇÃO ou ADEQUAÇÃO A UM PROPÓSITO PARTICULAR.
# Veja a GNU General Public License para mais detalhes.
#
# Você deve ter recebido uma cópia da GNU General Public License
# junto com este programa. Se não, veja <https://www.gnu.org/licenses/>


import sympy
from sympy.parsing.sympy_parser import parse_expr, standard_transformations, implicit_multiplication_application
#acima temos as bibliotecas do codigo

transformations = standard_transformations + (implicit_multiplication_application,)#isso aqui faz variaveis como 2x serem possiveis

class calculo:#noçoes de calculo
     def integraçoes_definidas(self):#integraçao definida
          print('seja bem vindo, vamos fazer integraçoes simples definidas')
          denifiçoes1 = int(input('diga o inicio de onde vamos integrar'))#a parte do inicio da area que vamos calcular
          denifiçoes2 = int(input('otimo, diga o fim de onde vamos integrar'))#a parte final
          varia = sympy.symbols(input('diga as variaveis e as separe com espaço'))#aqui ode encaixa as variaveis
          formulastr = input('printe sua formula').replace('^', '**')#aqui e colocado a formula
          formulas = parse_expr(formulastr, transformations=transformations)#aqui a formula e traduzida para o sympy
          integral = sympy.integrate(formulas,(varia, denifiçoes1, denifiçoes2))#temos a integral em si
          print(f'a sua integral de {denifiçoes1} ate {denifiçoes2} vai gerar {integral}')#seu resultado

     def integraçoes_indefinidas(self):#quase a mesma bosta da integral definida
          print('ola bem vindo as integrais indefinidas, por enquanto de variavels temos so x vamos atualizar')#preciso explicar?
          varia = sympy.symbols(input('diga as variaveis e as separe com espaço'))#variaveis
          formulastr = input('printe sua formula').replace('^', '**')#formula
          formulas = parse_expr(formulastr, transformations=transformations)#traduçao da formula para o sympy
          integral01 = sympy.integrate(formulas, varia)#aqui fazemos as integrais
          print(f'a sua formula tem a seguinte integral {integral01} + C')#vc realmente acha que iria esquecer do C? vc esta quase certo

