# Fila do SUS


## Começando

Essas instruções farão com que você tenha uma cópia do projeto em execução na sua máquina local para fins de desenvolvimento e teste. 

### Pré-requisitos
Antes de tudo é preciso ter uma copia do projeto na maquina, você pode fazer isso clonando o projeto.

```
git clone https://github.com/DBattisti/Fila_do_SUS.git
```

É necessário o compilador g++ para gerar o executável. 

```
sudo apt-get install g++
```
Caso esteja utilizando WINDOWS você pode fazer o download do [MinGW-w64](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-posix/seh/) , que vem com a biblioteca POSIX implementa para o uso das threads. Descompacte a pasta em C:\\, após isso adicione o caminho C:\mingw64\bin nas variaveis de ambiente.


## Executando os testes

Feito a instalação do compilador é só executar a instrução dentro da pasta do projeto

```
cd .../Fila_do_SUS/
make run
```

ou no Windows

```
cd .../Fila_do_SUS/
mingw32-make
start SUSQueue.exe
```