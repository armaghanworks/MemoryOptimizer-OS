#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>

using namespace std;

struct Process
{
    int id;
    int size;
    bool allocated;
    int blockID;
};

struct MemoryBlock
{
    int id;
    int size;
    bool allocated;
    int processID;
};

struct Result
{
    string algorithmName;

    vector<MemoryBlock> blocks;
    vector<Process> processes;

    int totalFragmentation = 0;
    double utilization = 0;
    int successCount = 0;
};

#endif