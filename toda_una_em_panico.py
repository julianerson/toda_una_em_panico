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
