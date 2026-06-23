#include <iostream>
#include <vector>
#include "memory.h"
#include "algorithms.h"
#include "visualizer.h"
#include "recommender.h"
#include "report.h"

using namespace std;

int main()
{
    int numberOfBlocks;
    int numberOfProcesses;

    vector<MemoryBlock> blocks;
    vector<Process> processes;

    cout << "===================================\n";
    cout << "SMART MEMORY OPTIMIZER\n";
    cout << "===================================\n\n";

    cout << "Enter Number of Memory Blocks: ";
    cin >> numberOfBlocks;

    for(int i = 0; i < numberOfBlocks; i++)
    {
        MemoryBlock block;

        block.id = i + 1;

        cout << "Enter Size of Block "
             << block.id
             << " (KB): ";

        cin >> block.size;

        block.allocated = false;
        block.processID = -1;

        blocks.push_back(block);
    }

    cout << "\nEnter Number of Processes: ";
    cin >> numberOfProcesses;

    for(int i = 0; i < numberOfProcesses; i++)
    {
        Process process;

        process.id = i + 1;

        cout << "Enter Memory for P"
             << process.id
             << " (KB): ";

        cin >> process.size;

        process.allocated = false;
        process.blockID = -1;

        processes.push_back(process);
    }

    Result first =
        firstFit(blocks, processes);

    Result best =
        bestFit(blocks, processes);

    Result worst =
        worstFit(blocks, processes);

    displayResult(first);
    displayResult(best);
    displayResult(worst);

    cout << "\n===================================\n";
    cout << "COMPARISON TABLE\n";
    cout << "===================================\n\n";

    cout << "Algorithm\tFragmentation\tUtilization\n";

    cout << "First Fit\t"
         << first.totalFragmentation
         << " KB\t\t"
         << first.utilization
         << "%\n";

    cout << "Best Fit\t"
         << best.totalFragmentation
         << " KB\t\t"
         << best.utilization
         << "%\n";

    cout << "Worst Fit\t"
         << worst.totalFragmentation
         << " KB\t\t"
         << worst.utilization
         << "%\n";

    recommend(first, best, worst);

    char choice;

    cout << "\n\nSave Report? (y/n): ";
    cin >> choice;

    if(choice == 'y' ||
       choice == 'Y')
    {
        saveReport(first, best, worst);
    }

    cout << "\nProgram Finished.\n";

    return 0;
}