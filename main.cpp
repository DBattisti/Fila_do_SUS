#include "SUSQueue.h"
#include <thread>
#include <chrono>

#define PUBTIMESTEP 10
#define CONTIMESTEP 5

/**
    Cria um paciente em um tempo randomico de 0 a 10 segundos e printa a fila
    O paciente criado recebe um @timeLeft randomico que varia de 30 a 720
*/
void patient_productor(SUSQueue *susq)
{
    while (true)
    {
        Patient *p = new Patient;
        //minimo 30 maximo 720
        p->timeLeft = (rand() % 690) + 30;

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

/**
    Pega o proximo da fila de 5 em 5 segundos e printa a fila
*/
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
    SUSQueue *susq = new SUSQueue;

    thread first(patient_productor, susq);
    thread second(patient_consumer, susq);

    // sincroniza as threads
    first.join();
    second.join();

    delete susq;

    return 0;
}
