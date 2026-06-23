#include "report.h"

#include <fstream>

void saveReport(Result first,
                Result best,
                Result worst)
{
    ofstream file("report.txt");

    Result results[3] =
    {
        first,
        best,
        worst
    };

    file << "SMART MEMORY OPTIMIZER REPORT\n\n";

    for(auto result : results)
    {
        file << "===================================\n";

        file << result.algorithmName << endl;

        file << "===================================\n";

        for(auto process : result.processes)
        {
            file << "P"
                 << process.id
                 << " -> ";

            if(process.allocated)
            {
                file << "Block "
                     << process.blockID;
            }
            else
            {
                file << "NOT ALLOCATED";
            }

            file << endl;
        }

        file << "\nFragmentation : "
             << result.totalFragmentation
             << " KB\n";

        file << "Utilization : "
             << result.utilization
             << "%\n\n";
    }

    file.close();

    cout << "\nReport Saved Successfully!\n";
}