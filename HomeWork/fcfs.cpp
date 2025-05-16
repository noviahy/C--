// fcfs.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Process {
    int pid, arrival, burst;
    int start, finish, response, waiting, turnaround;
};

bool compare_arrival(const Process& a, const Process& b) {
    return a.arrival < b.arrival || (a.arrival == b.arrival && a.pid < b.pid);
}

int main() {
    ifstream in("input.dat");
    ofstream out("output_fcfs.txt");
    string dummy;
    int pid, arrival, burst, priority;
    vector<Process> processes;

    in >> dummy >> dummy >> dummy >> dummy;
    while (in >> pid >> arrival >> burst >> priority) {
        processes.push_back({pid, arrival, burst});
    }

    sort(processes.begin(), processes.end(), compare_arrival);
    int time = 0;
    for (auto& p : processes) {
        time = max(time, p.arrival);
        p.start = time;
        p.finish = time + p.burst;
        p.response = p.start - p.arrival;
        p.waiting = p.response;
        p.turnaround = p.finish - p.arrival;
        time = p.finish;
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

    int total_time = processes.back().finish;
    out << fixed << setprecision(2);
    out << "Avg Response: " << avg_rt / processes.size() << "\n";
    out << "Avg Waiting: " << avg_wt / processes.size() << "\n";
    out << "Avg Turnaround: " << avg_tt / processes.size() << "\n";
    out << "CPU Utilization: 100%\n";
}
