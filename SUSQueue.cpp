#include <iostream>
#include <vector>

struct Patient {
    int arrivalTime;
    int timeLeft;
};

class SUSQueue {
    private:
    std::vector<Patient> sus;
    static int currentTime;

    private:
    void MakeHeap();
    void PushHeap();
    void PopHeap();
    void IsHeap();

    public:
    Patient NextOfQueue ();
    void Screening(Patient newPatient);
    
    static SUSQueue MergeQueue(SUSQueue leftQueue, SUSQueue rightQueue);
    static std::vector<SUSQueue> BreakQueue(SUSQueue oldQueue);
}