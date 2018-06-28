#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

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
            }
            else if (right_value < left_value)
            {
                if (right_value < parent_value)
                {
                    swap_index(parent_index, right_child(parent_index));
                    parent_index = right_child(parent_index);
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
    Retorna o index do pai
    */
    int parent(int index)
    {
        return floor(index / 2);
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
    Retorna o proximo paciente da fila
    @return o proximo paciente
    */
    Patient NextOfQueue()
    {
        return PopHeap();
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
        for (vector<Patient>::iterator it = sus.begin(); it != sus.end(); it++)
        {
            cout << it->maxTime << "\n";
        }
        cout << "\n";
    }
};

int main(int argc, char const *argv[])
{
    //Debugando a insercao dos nos
    //#######
    Patient *p = new Patient;
    p->maxTime = 20;

    Patient *p2 = new Patient;
    p2->maxTime = 15;

    Patient *p3 = new Patient;
    p3->maxTime = 12;

    Patient *p4 = new Patient;
    p4->maxTime = 13;

    SUSQueue *susq = new SUSQueue;
    susq->Screening(*p);
    susq->Screening(*p2);
    susq->Screening(*p3);
    susq->Screening(*p4);

    susq->Print();

    cout << susq->NextOfQueue().maxTime << "\n\n";

    susq->Print();

    cout << susq->NextOfQueue().maxTime << "\n\n";

    susq->Print();

    cout << susq->NextOfQueue().maxTime << "\n\n";

    susq->Print();

    //#######

    return 0;
}
