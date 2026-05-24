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
git = input("Vai dar git? s/n: ")

if git.strip().lower() == "s":
    # 1. Verifica se a pasta já é um repositório Git. Se não for, inicializa.
    if not os.path.exists(".git"):
        print("⚙️ Inicializando repositório Git...")
        subprocess.run("git init", shell=True)

    print("📁 Verificando arquivos...")
    
    # 2. Caminha por todas as pastas do projeto
    for raiz, pastas, arquivos in os.walk("."):
        
        # Ignora COMPLETAMENTE as pastas venv, __pycache__ e .git para não perder tempo nelas
        # Modificar a lista 'pastas' inline faz o os.walk pular essas subpastas
        pastas[:] = [p for p in pastas if p not in ["venv", "__pycache__", ".git"]]
        
        for arquivo in arquivos:
            caminho_completo = os.path.join(raiz, arquivo)
            
            # Adiciona o arquivo atual ao Git
            # Usar check=True faz o Python avisar se o comando falhar
            try:
                subprocess.run(f'git add "{caminho_completo}"', shell=True, check=True)
            except subprocess.CalledProcessError:
                print(f"❌ Erro ao adicionar: {caminho_completo}")

    # 3. Executa o Commit e o Push exibindo as mensagens do terminal
    subprocess.run("git commit -m 'atualizacao generica'", shell=True)
    subprocess.run("git push", shell=True)