#include <iostream>
#include <vector>
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
        float index = sus.size() - 1;
        while (sus.at(index).maxTime < sus.at(floor(index / 2)).maxTime && index > 0)
        {
            Patient aux = sus.at(index);
            sus.at(index) = sus.at(floor(index / 2));
            sus.at(floor(index / 2)) = aux;

            index = floor(index / 2);
        }
    }

    /**
    Retorna o topo do heap e promove um novo topo.
    @return o paciente no topo.
    */
    Patient PopHeap()
    {
        Patient p = sus.front();
        // TODO trocar o topo com o ultimo elemento e rabaixar
        return p;
    }

    /**
    Verifica se o vector e um heap minimo
    */
    void IsMinHeap()
    {
        // TODO verificar se o vector e um heap
    }

  public:
    /**
    Retorna o proximo paciente da fila
    @return o proximo paciente
    */
    Patient NextOfQueue();

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
    //#######

    return 0;
}
