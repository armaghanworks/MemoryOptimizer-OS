#include "visualizer.h"

#include <iomanip>

void drawBar(int size)
{
    int units = size / 50;

    cout << "[";

    for(int i = 0; i < units; i++)
    {
        cout << "#";
    }

    cout << "]";
}

void displayResult(Result result)
{
    cout << "\n===================================";
    cout << "\n" << result.algorithmName;
    cout << "\n===================================\n";

    cout << "\nMEMORY BAR VISUALIZATION\n\n";

    for(auto block : result.blocks)
    {
        cout << "Block "
             << block.id
             << " ";

        drawBar(block.size);

        cout << " ";

        if(block.allocated)
        {
            cout << "P"
                 << block.processID;
        }
        else
        {
            cout << "FREE";
        }

        cout << " ("
             << block.size
             << " KB)";

        cout << endl;
    }

    cout << "\nPROCESS ASSIGNMENT\n\n";

    for(auto process : result.processes)
    {
        cout << "P"
             << process.id
             << " ("
             << process.size
             << " KB) -> ";

        if(process.allocated)
        {
            cout << "Block "
                 << process.blockID;
        }
        else
        {
            cout << "NOT ALLOCATED";
        }

        cout << endl;
    }

    cout << fixed << setprecision(2);

    cout << "\n===================================\n";
    cout << "STATISTICS\n";
    cout << "===================================\n";

    cout << "Total Fragmentation : "
         << result.totalFragmentation
         << " KB\n";

    cout << "Memory Utilization : "
         << result.utilization
         << "%\n";

    cout << "Allocated Processes : "
         << result.successCount
         << "/"
         << result.processes.size()
         << endl;
}