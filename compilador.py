import subprocess
import os
from time import sleep

til = os.path.expanduser("~/")
for root,dirs,files in os.walk(f"{til}/Desktop/projetos/", topdown=True):
    for dir in dirs:
        if dir == "win_toda_una_em_panico" or dir == "linux_toda_una_em_panico":
            subprocess.run(f"rm -rf {til}/Desktop/projetos/{dir}",shell=True)
    dirs.clear()
subprocess.run(f"7z x {til}/Desktop/projetos/baixar_toda_una_em_panico/linux_toda_una_em_panico.7z -o{til}/Desktop/projetos",shell=True)
subprocess.run(f"7z x {til}/Desktop/projetos/baixar_toda_una_em_panico/win_toda_una_em_panico.7z -o{til}/Desktop/projetos",shell=True)
jeej = []
for root,dir,files in os.walk(".", topdown=True):
    dir[:] = []
    for file in files:
        if file[-3:] == ".so" or file[-4:] == ".dll":
            subprocess.run(f"rm {file}",shell=True)
        elif file[-2:] == ".c" or file[-3:] == ".ld" or file[-2:] == ".h":
            subprocess.run(f"cp -f {file} {til}/Desktop/projetos/win_toda_una_em_panico/codigos_dev",shell=True)
        elif file[-3:] == ".py":
            subprocess.run(f"cp -f {file} {til}/Desktop/projetos/win_toda_una_em_panico",shell=True)
subprocess.run("gcc -fPIC -shared -o calculadora.so calculadora.c tinyexpr.c -lm -Wl,-T,teste.ld && x86_64-w64-mingw32-gcc -shared -o calculadora.dll calculadora.c tinyexpr.c -lm",shell=True)
sleep(10)
subprocess.run("strip calculadora.so calculadora.dll", shell=True)
subprocess.run(f"cp -f calculadora.dll {til}/Desktop/projetos/win_toda_una_em_panico",shell=True)
subprocess.run(f"cp -f calculadora.so {til}/Desktop/projetos/linux_toda_una_em_panico",shell=True)