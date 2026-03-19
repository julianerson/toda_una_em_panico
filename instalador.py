import os
import subprocess
from time import sleep as mimir
#isso deve compilar o .c
nome = os.name
subprocess.run("pip install scipy sympy InquirerPy")#instala as bibliotecas do python
if nome == "nt":#ve se e windows
    subprocess.run(r"gcc -shared -o calculadora.dll calculadora.c tinyexpr.c -Wl,--add-stdcall-alias",shell=True)#compila para windows
elif nome == "posix":#ve se e linux
    subprocess.run(r"gcc -shared -fPIC calculadora.c tinyexpr.c -o calculadora.so -lm",shell=True)#compila para linux