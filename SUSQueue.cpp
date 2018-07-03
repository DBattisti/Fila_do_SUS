#include "SUSQueue.h"

void SUSQueue::PushHeap(Patient p)
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

Patient SUSQueue::PopHeap()
{
    swap_index(0, last_index());
    Patient p = sus.back();
    sus.pop_back();

    if (sus.size() == 0)
    {
        return p;
    }

    int parent_index = 0;
    //Enquanto ele nao for uma folha e nao for um numero invalido
    while (parent_index <= parent(last_index()) && parent_index >= 0)
    {
        int parent_value = sus.at(parent_index).maxTime;
        int left_index = left_child(parent_index);
        int left_value = sus.at(left_index).maxTime;

        int right_index = right_child(parent_index);
        if (right_index > 0)
        {
            int right_value = sus.at(right_index).maxTime;

            if (left_value < right_value)
            {
                if (left_value < parent_value)
                {
                    swap_index(parent_index, left_index);
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
                    swap_index(parent_index, right_index);
                    parent_index = right_index;
                }
                else if (right_value == parent_value)
                {
                    parent_index = -1;
                }
            }
        }
        else
        {
            if (left_value < parent_value)
            {
                swap_index(parent_index, left_index);
                parent_index = right_child(parent_index);
            }
            else
            {
                parent_index = -1;
            }
        }
    }

    return p;
}

void SUSQueue::IsMinHeap()
{
    // TODO verificar se o vector e um heap
}

void SUSQueue::swap_index(int index, int other_index)
{
    Patient aux = sus.at(index);
    sus.at(index) = sus.at(other_index);
    sus.at(other_index) = aux;
}

int SUSQueue::left_child(int index)
{
    int left = (index * 2) + 1;
    if (left > last_index())
    {
        return -1;
    }
    else
    {
        return left;
    }
}

int SUSQueue::right_child(int index)
{
    int right = (index * 2) + 2;
    if (right > last_index())
    {
        return -1;
    }
    else
    {
        return right;
    }
}

int SUSQueue::parent(int index)
{
    return floor((index - 1) / 2);
}

int SUSQueue::last_index()
{
    return sus.size() - 1;
}

void SUSQueue::InitTime()
{
    //currentTime = 0;
}

Patient SUSQueue::NextOfQueue()
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

void SUSQueue::Screening(Patient newPatient)
{
    PushHeap(newPatient);
}

void SUSQueue::Print()
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