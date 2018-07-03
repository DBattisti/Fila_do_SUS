# Fila do SUS

## Trabalho da disciplina de EDPA 2018/01

* Exercício: Fila do SUS
* Número do exercício: 2505
* Juízes online: URI Online Judge
* [Link do exercício original]( https://www.urionlinejudge.com.br/judge/pt/problems/view/2506)

### Descrição
Os pacientes que chegam na fila do SUS passam por uma triagem imediatamente e vão para a fila de atendimento. Na triagem a enfermeira anota o horário de entrada do paciente e quantos minutos ele tem até que sua condição de saúde se torne crítica. Sabe-se que os pacientes são atendidos de 30 em 30 minutos sempre nas horas cheias ou meias horas) quando na fila de atendimento. O início da triagem e do atendimento se dá às 7h da manhã, se não há nenhum paciente sendo atendido e a fila está vazia, o primeiro paciente é atendido no instante que chega na triagem. O médico atende até o último paciente na fila. A reocupação é se algum paciente atingiu uma condição crítica enquanto não tenha sido atendido. Um relógio global é atualizado em 30 minutos a cada atendimento realizado pelos médicos. Cada paciente tem um tempo máximo que é considerado como sua prioridade na fila. Este tempo máximo é calculado pelo tempo de chegada mais o tempo necessário para seu estado crítico aumentar. Para tanto você foi convidado para verificar na fila quantos pacientes atingem a condição crítica antes de serem atendidos.

### Entrada
A entrada contém vários casos de teste. Cada caso de teste começa com uma linha com o número inteiro N, 0 < N < 25 o número de pacientes que chegam à triagem. A seguir são N linhas com os valores inteiros H, M e C, com 7 < H < 19, e 0 ≤ M <60, a hora e minuto que o paciente chega à triagem. O paciente da linha i sempre chega antes que, e no máximo junto com, o paciente da linha i + 1. E 0 ≤C ≤ 720 o número de minutos antes do paciente atingir a condição crítica de saúde.

### Saída
Para cada caso de teste pede-se que se imprima em uma linha única o número de
pacientes que atingiram a condição crítica ainda na fila de atendimento.

## Começando

Essas instruções farão com que você tenha uma cópia do projeto em execução na sua máquina local para fins de desenvolvimento e teste. 

### Pré-requisitos

É necessário o compilador g++

```
sudo apt-get install g++
```

## Executando os testes

```
make run
```
