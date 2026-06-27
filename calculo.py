#//licença GNU
#/*    toda_una_em_panico | a calculadora para engenheiros novatos desesperados
#*    Copyright (C) 2026  
#*   Contact: nilson.m.b.abreu@gmail.com
#*
#*    This program is free software: you can redistribute it and/or modify
#*    it under the terms of the GNU General Public License as published by
#*    the Free Software Foundation, either version 3 of the License, or
#*    (at your option) any later version.
#*
#*    This program is distributed in the hope that it will be useful,
#*    but WITHOUT ANY WARRANTY; without even the implied warranty of
#*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#*    GNU General Public License for more details.
#*    You should have received a copy of the GNU General Public License
#*    along with this program.  If not, see <https://www.gnu.org/licenses/>*/

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

