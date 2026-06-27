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
print("""toda_una_em_panico Copyright (C) 2026  nilson moreira borges de abreu
    Este programa vem com ABSOLUTAMENTE NENHUMA GARANTIA; 
     Este é um software livre, e você pode redistribuí-lo
    sob certas condições; entre em 'licenca-glp' para obter detalhes.""")
while True:#aqui onde o user começa a ver
     AGUI = inquirer.select(
            message='vamos aos calculos',
            choices=['licenca-glp','sair','info','integracao indefinida', 'integraçao definida','calculadoraC']
            ).execute()#menu principal
     if 'sair' in AGUI:#sai
          break
     elif 'licenca-glp' in AGUI:
          print("vamos la a licença e :\n\n")
          caminho_arquivo = 'LICENCE.md'

          # Abre o arquivo com a codificação UTF-8 para suportar acentos
          with open(caminho_arquivo, 'r', encoding='utf-8') as arquivo:
               conteudo = arquivo.read()
               print(conteudo)
     elif 'info' in AGUI:#da as informaçoes basicas
          informacoes()
     elif 'integracao indefinida' in AGUI:
          calc.integraçoes_indefinidas()
          print('otimo, temos mais contas otaro')
     elif 'integraçao definida' in AGUI:
          calc.integraçoes_definidas()
     elif 'calculadoraC' in AGUI:

          if os.name == "posix":#daqui ate a linha 47 e usado a biblioteca compartilhada desse codigo
               oioi = os.path.abspath("calculadora.so")
          if os.name == "nt":          
               oioi = os.path.abspath("calculadora.dll")
          teste = ctypes.CDLL(oioi)

          mom = inquirer.select(#escolhe o comando para c
               message='o que vc quer?',
               choices=["sair","formulas","matrizes","vetores"]
               ).execute()#menu principal
          print("\n"*1000)
          print("""dica:
                calculos aqui sao diferentes
                para potencia= pow(numero,expoente)
                raiz quadrada=sqrt(x)
                para cosseno = cos(x)
                para tangente = tan(x)
                arctan = atan(x)
                arctan(x/y) = atan2(x,y)
                log natural = log(x)
                log de 10 = log10(x)
                pi = p""")
          mimir(8)
          if "sair" in mom:
               break
          elif "formulas" in mom:
               formulas_gui = inquirer.select(
                    message='formula bruta? nao se preucupe, so escolha a soluçao no catalogo',
                    choices=["loop","cramer"]
                    ).execute()#menu
               if "loop" in formulas_gui:
                    teste.somatorio()
               elif "cramer" in formulas_gui:
                    teste.crack()
          elif "matrizes" in mom:
               matrizes_gui = inquirer.select(
                    message='matrizes, isso me intriga, bem aqui as nossas soluçoes abaixo',
                    choices=["soma-subtraçao","multiplicacao","determinantes"]
                    ).execute()
               if "soma-subtraçao" in matrizes_gui:
                    teste.soma_matriz()
               elif "multiplicacao" in matrizes_gui:
                    teste.matrizes_multiplicadas()
               elif "determinantes" in matrizes_gui:
                    teste.determinantes()
          elif "vetores" in mom:
               vetor_gui = inquirer.select(message='VETOR! sou eu, esse e meu nome porque cometo CRIMES com precisao e magnetude',
                    choices=["decomposicao","soma-vetor","soma_vetor_complexa","multiplicacao_vetores"]
                    ).execute()
               if "decomposicao" in vetor_gui:
                    teste.decomposicao_vetor()
               elif "soma-vetor" in vetor_gui:
                    teste.soma_vetor_simples()
               elif "soma_vetor_complexa" in vetor_gui:
                    teste.soma_vetor_complexo()
               elif "multiplicacao_vetores" in vetor_gui:
                    teste.multiplicaçao_vetores()
          del teste#isso retira os lixos de memoria, mas tambem retira o uso da calculadora
          continue
