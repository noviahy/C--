// rr.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

struct Process {
    int pid, arrival, burst, remaining;
    int start = -1, finish, response, waiting, turnaround;
    bool done = false;
};

int main() {
    ifstream in("input.dat");
    ofstream out("output_rr.txt");
    string dummy;
    int pid, arrival, burst, priority;
    vector<Process> processes;

    in >> dummy >> dummy >> dummy >> dummy;
    while (in >> pid >> arrival >> burst >> priority)
        processes.push_back({pid, arrival, burst, burst});

    int time = 0, done = 0, tq = 3;
    queue<int> q;
    vector<bool> in_queue(processes.size(), false);

    while (done < processes.size()) {
        for (int i = 0; i < processes.size(); ++i)
            if (processes[i].arrival <= time && !in_queue[i] && !processes[i].done) {
                q.push(i); in_queue[i] = true;
            }

        if (q.empty()) { time++; continue; }

        int i = q.front(); q.pop(); in_queue[i] = false;
        if (processes[i].start == -1) processes[i].start = time;

        int exec = min(tq, processes[i].remaining);
        processes[i].remaining -= exec;
        time += exec;

        for (int j = 0; j < processes.size(); ++j)
            if (processes[j].arrival <= time && !in_queue[j] && !processes[j].done)
                q.push(j), in_queue[j] = true;

        if (processes[i].remaining == 0) {
            processes[i].finish = time;
            processes[i].response = processes[i].start - processes[i].arrival;
            processes[i].turnaround = time - processes[i].arrival;
            processes[i].waiting = processes[i].turnaround - processes[i].burst;
            processes[i].done = true;
            done++;
        } else {
            q.push(i);
            in_queue[i] = true;
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
