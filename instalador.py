import os
import subprocess
from time import sleep as mimir
#isso deve compilar o .c
nome = os.name
subprocess.run("pip install scipy sympy InquirerPy")
if nome == "nt":
    subprocess.run(r"gcc -shared -o calculadora.dll calculadora.c tinyexpr.c -Wl,--add-stdcall-alias",shell=True)
elif nome == "posix":
    subprocess.run(r"gcc -shared -fPIC calculadora.c tinyexpr.c -o calculadora.so -lm",shell=True)