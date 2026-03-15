import os
import subprocess
#isso deve compilar o .c
nome = os.name

if nome == "nt":
    lugar = subprocess.check_output('dir /s "calculadora.c"',shell=True,text=True)
    subprocess.run(r"cd {} && gcc -shared -o calculadora.dll calculadora.c -Wl,--add-stdcall-alias".format(lugar), shell=True)
elif nome == "posix":
    lugar = subprocess.check_output('find / -iname calculadora.c',shell=True,text=True)
    subprocess.run(r"cd {} && gcc -c -fPIC calculadora.c tinyexpr.c -o calculadora.o && gcc -shared -o calculadora.so calculadora.o".format(lugar),shell=True)