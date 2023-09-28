#include<bits/stdc++.h>
using namespace std;
struct Process {
    int pid;        // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
};

bool compare(Process p1, Process p2) {
    return p1.arrival < p2.arrival;
}

void fcfs(Process processes[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    wt[0] = 0;
    tat[0] = processes[0].burst;

    for (int i = 1; i < n; i++)
    {
        // Waiting time for current process = Waiting time of previous process + Burst time of previous process
        wt[i] = wt[i-1] + processes[i-1].burst - processes[i].arrival;

        // Turnaround time for current process = Burst time + Waiting time
        tat[i] = processes[i].burst + wt[i];

        total_wt += wt[i];
        total_tat += tat[i];
    }

    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;

    cout << "Process\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t\t" << processes[i].arrival << "\t\t" << processes[i].burst << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
    cout << "\nAverage Waiting Time: " << avg_wt << endl;
    cout << "Average Turnaround Time: " << avg_tat << endl;
}

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process processes[n];
    for (int i = 0; i < n; i++) {
        cout << "\nProcess " << i+1 << "\nEnter Arrival Time: ";
        cin >> processes[i].arrival;
        cout << "Enter Burst Time: ";
        cin >> processes[i].burst;
        processes[i].pid = i+1;
    }

    sort(processes, processes+n, compare);    // Sort processes according to their arrival time
    fcfs(processes, n);

    return 0;
}
