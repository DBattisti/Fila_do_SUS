#include "SUSQueue.h"
#include <thread>
#include <chrono>

#define NUMPAT 10
#define PUBTIMESTEP 10
#define CONTIMESTEP 5

void patient_productor(SUSQueue *susq)
{
    while (true)
    {
        Patient *p = new Patient;
        p->timeLeft = rand() % 720;

        susq->Screening(*p);
    
        cout << "Um paciente entrou na fila!" << endl;
        susq->PrintInLine();

        this_thread::sleep_for(chrono::seconds(rand() % PUBTIMESTEP));

        if (susq->IsFinished())
        {
            return;
        }
    }
}

void patient_consumer(SUSQueue *susq)
{
    while (true)
    {
        try
        {
            Patient p = susq->NextOfQueue();

            cout << "Um paciente foi atendido!" << endl;
            susq->PrintInLine();

        }
        catch (MyException e)
        {
            cout << e.what() << endl;
            if (susq->IsFinished())
            {
                return;
            }
        }

        this_thread::sleep_for(chrono::seconds(CONTIMESTEP));
    }
}

int main(int argc, char const *argv[])
{
    // //Debugando a insercao dos nos
    // //#######
    // SUSQueue *susq = new SUSQueue;

    // //Adiciona @NUMPAT pacientes na fila com tempos aleatorios
    // for (int i = 0; i < NUMPAT; i++)
    // {
    //     Patient *p = new Patient;
    //     p->timeLeft = ( rand() % 100 ) + 30 ;

    //     susq->Screening(*p);
    // }

    // susq->Print();

    // //Tenta remover @NUMPAT pacientes na fila
    // for (int i = 0; i < NUMPAT; i++)
    // {
    //     try
    //     {
    //         Patient p = susq->NextOfQueue();
    //         cout << p.maxTime << endl;
    //     }
    //     catch (MyException e)
    //     {
    //         cout << e.what() << endl;
    //     }
    // }

    // //#######

    SUSQueue *susq = new SUSQueue;

    thread first(patient_productor, susq);
    thread second(patient_consumer, susq);

    // synchronize threads:
    first.join();  // pauses until first finishes
    second.join(); // pauses until second finishes

    delete susq;
    
    return 0;
}
