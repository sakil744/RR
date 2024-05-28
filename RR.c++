#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n], at[n], tat[n], wt[n], rem_bt[n];
    double avgtat = 0, avgwt = 0;

    cout << "Enter burst time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "For process " << i + 1 << ": ";
        cin >> bt[i];
        rem_bt[i] = bt[i]; // Initialize remaining burst time
    }

    int qt;
    cout << "Enter quantum time: ";
    cin >> qt;

    int current_time = 0;
    bool done;

    int gantt_chart[100]; // Array to store the process sequence in Gantt Chart
    int gc_index = 0; // Index to keep track of Gantt Chart positions

    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = false;
                if (rem_bt[i] > qt) {
                    current_time += qt;
                    rem_bt[i] -= qt;
                    gantt_chart[gc_index++] = i + 1; // Add process to Gantt Chart
                } else {
                    current_time += rem_bt[i];
                    wt[i] = current_time - bt[i];
                    rem_bt[i] = 0;
                    gantt_chart[gc_index++] = i + 1; // Add process to Gantt Chart
                }
            }
        }
    } while (!done);

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }

    avgwt /= n;
    avgtat /= n;

    cout << "\nProcess\tBurst Time\tTurn Around Time\tWaiting Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t\t" << bt[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;
    }

    cout << "Average Waiting Time: " << avgwt << endl;
    cout << "Average Turn Around Time: " << avgtat << endl;

    // Display Gantt Chart
    cout << "\nGantt Chart:\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    for (int i = 0; i < gc_index; i++) {
        cout << "| P" << gantt_chart[i] << " ";
    }
    cout << "|\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    return 0;
}
