#include "SUSQueue.h"

#define NUMPAT 10

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