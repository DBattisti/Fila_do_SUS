#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#define TIMESTEP 30
#define MAXTIME 720

using namespace std;

/**
    Estrutura de cada paciente
    @timeLeft tempo restante para piorar 
    @maxTime tempo maximo para piorar o seu estado de saude
*/
struct Patient
{
    int timeLeft;
    int maxTime;
};

/**
    Estrutura para o lancamento de excecoes
*/
struct MyException : public exception
{
    string s;
    MyException(string ss) : s(ss) {}
    ~MyException() throw() {}
    const char *what() const throw() { return s.c_str(); }
};

/**
    Classe responsavel por manter a manuntencao de uma fila
    @screening_log log da insercao na fila de prioridade
    @treatment_log log da remocao na fila de prioridade
    @sus vector com os pacientes.
    @currentTime tempo global das fila, usado para comparar com o maxTime do paciente
*/
class SUSQueue
{
  private:
    ofstream screening_log;
    ofstream treatment_log;

    vector<Patient> sus;
    int currentTime;

  private:
    /**
    Insere um novo paciente na fila de prioridades
    @param o novo paciente a ser inserido.
    */
    void PushHeap(Patient p);

    /**
    Retorna o topo do heap e promove um novo topo.
    @return o paciente no topo.
    */
    Patient PopHeap();

    /**
    Troca os elementos nas posicoes indicadas pelos parametros
    */
    void swap_index(int index, int other_index);

    /**
    Retorna o index do filho a esquerda
    */
    int left_child(int index);

    /**
    Retorna o index do filho a direita
    */
    int right_child(int index);

    /**
    Retorna o index do pai. se o index for 0 então retorna 0
    */
    int parent(int index);

    /**
    Retorna o ultimo index do vector
    */
    int last_index();

  public:
    /**
    Inicializa o tempo global das filas
    */
    SUSQueue();

    /**
    Fecha os arquivos
    */
    ~SUSQueue();

    /**
    Retorna o proximo paciente da fila
    @return o proximo paciente
    */
    Patient NextOfQueue();

    /**
    Metodo de triagem, recebe um paciente e o coloca na posicao adequada
    @param o paciente que vai passar pela triagem
    */
    void Screening(Patient newPatient);

    /**
    Verifica se o tempo de atendimento encerrou
    */
    bool IsFinished();

    /**
    Printa na tela o heap com o tempo maximo de cada paciente
    */
    void Print();

    /**
    Mesmo que o metodo acima, mas printa somente em uma linha
    */
    void PrintInLine();
};