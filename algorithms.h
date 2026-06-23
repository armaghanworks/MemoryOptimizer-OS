#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "memory.h"

Result firstFit(vector<MemoryBlock> blocks,
                vector<Process> processes);

Result bestFit(vector<MemoryBlock> blocks,
               vector<Process> processes);

Result worstFit(vector<MemoryBlock> blocks,
                vector<Process> processes);

#endif