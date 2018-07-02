#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

/**
    Estrutura de cada paciente
    @arrivalTime tempo em que ele chegou na triagem.
    @maxTime tempo maximo para piorar o seu estado de saude
*/
struct Patient
{
    int arrivalTime;
    int maxTime;
};

/**
    Estrutura para o lancamento de excecoes
*/
struct MyException : public exception
{
    std::string s;
    MyException(std::string ss) : s(ss) {}
    ~MyException() throw() {}
    const char *what() const throw() { return s.c_str(); }
};

/**
    Classe responsavel por manter a manuntencao de uma fila
    @sus vector com os pacientes.
    @currentTime tempo global das fila, usado para comparar com o maxTime do paciente
    */
class SUSQueue
{
  private:
    vector<Patient> sus;
    static int currentTime;

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
    Verifica se o vector e um heap minimo
    */
    void
    IsMinHeap();

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
    Inicializa o tempo global das filas;
    */
    static void InitTime();

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

    void Print();
};