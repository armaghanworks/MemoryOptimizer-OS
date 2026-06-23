#include "algorithms.h"

Result firstFit(vector<MemoryBlock> blocks,
                vector<Process> processes)
{
    Result result;

    result.algorithmName = "First Fit";
    result.blocks = blocks;
    result.processes = processes;

    int totalMemory = 0;
    int usedMemory = 0;

    for(auto block : result.blocks)
    {
        totalMemory += block.size;
    }

    for(int i = 0; i < result.processes.size(); i++)
    {
        for(int j = 0; j < result.blocks.size(); j++)
        {
            if(!result.blocks[j].allocated &&
               result.blocks[j].size >= result.processes[i].size)
            {
                result.blocks[j].allocated = true;
                result.blocks[j].processID =
                    result.processes[i].id;

                result.processes[i].allocated = true;
                result.processes[i].blockID =
                    result.blocks[j].id;

                usedMemory += result.processes[i].size;

                result.totalFragmentation +=
                    result.blocks[j].size -
                    result.processes[i].size;

                result.successCount++;

                break;
            }
        }
    }

    result.utilization =
        ((double)usedMemory / totalMemory) * 100;

    return result;
}

Result bestFit(vector<MemoryBlock> blocks,
               vector<Process> processes)
{
    Result result;

    result.algorithmName = "Best Fit";
    result.blocks = blocks;
    result.processes = processes;

    int totalMemory = 0;
    int usedMemory = 0;

    for(auto block : result.blocks)
    {
        totalMemory += block.size;
    }

    for(int i = 0; i < result.processes.size(); i++)
    {
        int bestIndex = -1;

        for(int j = 0; j < result.blocks.size(); j++)
        {
            if(!result.blocks[j].allocated &&
               result.blocks[j].size >= result.processes[i].size)
            {
                if(bestIndex == -1 ||
                   result.blocks[j].size <
                   result.blocks[bestIndex].size)
                {
                    bestIndex = j;
                }
            }
        }

        if(bestIndex != -1)
        {
            result.blocks[bestIndex].allocated = true;

            result.blocks[bestIndex].processID =
                result.processes[i].id;

            result.processes[i].allocated = true;

            result.processes[i].blockID =
                result.blocks[bestIndex].id;

            usedMemory += result.processes[i].size;

            result.totalFragmentation +=
                result.blocks[bestIndex].size -
                result.processes[i].size;

            result.successCount++;
        }
    }

    result.utilization =
        ((double)usedMemory / totalMemory) * 100;

    return result;
}

Result worstFit(vector<MemoryBlock> blocks,
                vector<Process> processes)
{
    Result result;

    result.algorithmName = "Worst Fit";
    result.blocks = blocks;
    result.processes = processes;

    int totalMemory = 0;
    int usedMemory = 0;

    for(auto block : result.blocks)
    {
        totalMemory += block.size;
    }

    for(int i = 0; i < result.processes.size(); i++)
    {
        int worstIndex = -1;

        for(int j = 0; j < result.blocks.size(); j++)
        {
            if(!result.blocks[j].allocated &&
               result.blocks[j].size >= result.processes[i].size)
            {
                if(worstIndex == -1 ||
                   result.blocks[j].size >
                   result.blocks[worstIndex].size)
                {
                    worstIndex = j;
                }
            }
        }

        if(worstIndex != -1)
        {
            result.blocks[worstIndex].allocated = true;

            result.blocks[worstIndex].processID =
                result.processes[i].id;

            result.processes[i].allocated = true;

            result.processes[i].blockID =
                result.blocks[worstIndex].id;

            usedMemory += result.processes[i].size;

            result.totalFragmentation +=
                result.blocks[worstIndex].size -
                result.processes[i].size;

            result.successCount++;
        }
    }

    result.utilization =
        ((double)usedMemory / totalMemory) * 100;

    return result;
}