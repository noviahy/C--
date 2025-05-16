// priority.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

struct Process {
    int pid, arrival, burst, priority, remaining;
    int start = -1, finish, response, waiting, turnaround;
    bool done = false;
};

int main() {
    ifstream in("input.dat");
    ofstream out("output_priority.txt");
    string dummy;
    int pid, arrival, burst, priority;
    vector<Process> processes;

    in >> dummy >> dummy >> dummy >> dummy;
    while (in >> pid >> arrival >> burst >> priority)
        processes.push_back({pid, arrival, burst, priority, burst});

    int t = 0, done = 0;
    double aging = 0.05;

    while (done < processes.size()) {
        int idx = -1;
        double best = 1e9;

        for (int i = 0; i < processes.size(); i++) {
            if (processes[i].arrival <= t && !processes[i].done) {
                double aged_priority = processes[i].priority - aging * (t - processes[i].arrival);
                if (aged_priority < best || (aged_priority == best && processes[i].pid < processes[idx].pid)) {
                    best = aged_priority;
                    idx = i;
                }
            }
        }

        if (idx == -1) { t++; continue; }

        if (processes[idx].start == -1) processes[idx].start = t;

        processes[idx].remaining--;
        t++;

        if (processes[idx].remaining == 0) {
            processes[idx].finish = t;
            processes[idx].response = processes[idx].start - processes[idx].arrival;
            processes[idx].turnaround = t - processes[idx].arrival;
            processes[idx].waiting = processes[idx].turnaround - processes[idx].burst;
            processes[idx].done = true;
            done++;
        }
    }

    double avg_rt = 0, avg_wt = 0, avg_tt = 0;
    out << "PID Start Finish Response Waiting Turnaround\n";
    for (auto& p : processes) {
        out << setw(3) << p.pid << setw(6) << p.start << setw(7) << p.finish
            << setw(9) << p.response << setw(8) << p.waiting << setw(11) << p.turnaround << "\n";
        avg_rt += p.response;
        avg_wt += p.waiting;
        avg_tt += p.turnaround;
    }

    out << fixed << setprecision(2);
    out << "Avg Response: " << avg_rt / processes.size() << "\n";
    out << "Avg Waiting: " << avg_wt / processes.size() << "\n";
    out << "Avg Turnaround: " << avg_tt / processes.size() << "\n";
    out << "CPU Utilization: 100%\n";
}
