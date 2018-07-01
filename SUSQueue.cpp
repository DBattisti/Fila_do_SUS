#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

#define NUMPAT 4

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
    void PushHeap(Patient p)
    {
        sus.push_back(p);

        int child_index = last_index();

        int parent_value = sus.at(parent(child_index)).maxTime;
        int child_value = sus.at(child_index).maxTime;

        while (child_value < parent_value && child_index > 0)
        {
            swap_index(child_index, parent(child_index));
            child_index = parent(child_index);

            parent_value = sus.at(parent(child_index)).maxTime;
            child_value = sus.at(child_index).maxTime;
        }
    }

    /**
    Retorna o topo do heap e promove um novo topo.
    @return o paciente no topo.
    */
    Patient PopHeap()
    {
        swap_index(0, last_index());
        Patient p = sus.back();
        sus.pop_back();

        if (sus.size() == 0)
        {
            return p;
        }

        int parent_index = 0;
        while (parent_index <= floor(last_index() / 2) && parent_index >= 0)
        {
            int parent_value = sus.at(parent_index).maxTime;
            int left_value = sus.at(left_child(parent_index)).maxTime;
            int right_value = sus.at(right_child(parent_index)).maxTime;

            if (left_value < right_value)
            {
                if (left_value < parent_value)
                {
                    swap_index(parent_index, left_child(parent_index));
                    parent_index = left_child(parent_index);
                }
                else if (left_value == parent_value)
                {
                    parent_index = -1;
                }
            }
            else if (right_value < left_value)
            {
                if (right_value < parent_value)
                {
                    swap_index(parent_index, right_child(parent_index));
                    parent_index = right_child(parent_index);
                }
                else if (right_value == parent_value)
                {
                    parent_index = -1;
                }
            }
            else
            {
                parent_index = -1;
            }
        }

        return p;
    }

    /**
    Verifica se o vector e um heap minimo
    */
    void
    IsMinHeap()
    {
        // TODO verificar se o vector e um heap
    }

    /**
    Troca os elementos nas posicoes indicadas pelos parametros
    */
    void swap_index(int index, int other_index)
    {
        Patient aux = sus.at(index);
        sus.at(index) = sus.at(other_index);
        sus.at(other_index) = aux;
    }

    /**
    Retorna o index do filho a esquerda
    */
    int left_child(int index)
    {
        int left = (index * 2) + 1;
        if (left > last_index())
        {
            return index;
        }
        else
        {
            return left;
        }
    }

    /**
    Retorna o index do filho a direita
    */
    int right_child(int index)
    {
        int right = (index * 2) + 2;
        if (right > last_index())
        {
            return index;
        }
        else
        {
            return right;
        }
    }

    /**
    Retorna o index do pai. se o index for 0 então retorna 0
    */
    int parent(int index)
    {
        return floor((index - 1) / 2);
    }

    /**
    Retorna o ultimo index do vector
    */
    int last_index()
    {
        return sus.size() - 1;
    }

  public:
    /**
    Inicializa o tempo global das filas;
    */
    static void InitTime()
    {
        currentTime = 0;
    }

    /**
    Retorna o proximo paciente da fila
    @return o proximo paciente
    */
    Patient NextOfQueue()
    {
        if (!sus.empty())
        {
            return PopHeap();
        }
        else
        {
            throw MyException("A fila esta vazia");
        }
    }

    /**
    Metodo de triagem, recebe um paciente e o coloca na posicao adequada
    @param o paciente que vai passar pela triagem
    */
    void Screening(Patient newPatient)
    {
        PushHeap(newPatient);
    }

    void Print()
    {
        cout << "Pessoas na fila: " << sus.size() << endl;
        cout << "[pos] maxTime"
             << "\n";
        int i = 0;
        for (vector<Patient>::iterator it = sus.begin(); it != sus.end(); it++)
        {
            cout << "[" << i << "] " << it->maxTime << endl;
            i++;
        }
        cout << "\n";
    }
};

int main(int argc, char const *argv[])
{
    //Debugando a insercao dos nos
    //#######
    SUSQueue *susq = new SUSQueue;

    //Adiciona @NUMPAT pacientes na fila com tempos aleatorios
    for (int i = 0; i < NUMPAT; i++)
    {
        Patient *p = new Patient;
        p->maxTime = rand() % 100;

        susq->Screening(*p);
    }

    susq->Print();

    //Tenta remover @NUMPAT pacientes na fila
    for (int i = 0; i < NUMPAT; i++)
    {
        try
        {
            Patient p = susq->NextOfQueue();
            cout << p.maxTime << endl;
        }
        catch (MyException e)
        {
            cout << e.what() << endl;
        }
    }

    //#######

    return 0;
}