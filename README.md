# 🧠 Smart Memory Optimizer (Operating Systems Project)

A comprehensive C++ console application that simulates, compares, and analyzes three fundamental memory allocation algorithms: **First Fit**, **Best Fit**, and **Worst Fit**. The program dynamically allocates processes to memory blocks, calculates internal fragmentation, measures memory utilization, and provides an intelligent recommendation on which algorithm performed best for the given input.

## 🌟 Key Features

### 🖥️ Core Simulation
- **Dynamic Input:** Accepts custom memory block sizes and process memory requirements from the user.
- **Algorithm Comparison:** Simultaneously runs First Fit, Best Fit, and Worst Fit algorithms on the same dataset.
- **Metrics Calculation:** Accurately calculates Total Internal Fragmentation (in KB) and Memory Utilization (%) for each algorithm.

### 📊 Visualization & Reporting
- **ASCII Bar-Chart Visualizer:** Draws a real-time visual representation of memory blocks, showing which processes are allocated and how much space is free.
- **Detailed Comparison Table:** Outputs a side-by-side console table comparing fragmentation and utilization across all three algorithms.
- **Smart Recommendation Engine:** Automatically calculates a performance score (Utilization - Fragmentation) and recommends the most efficient algorithm for the specific input.
- **Persistent Reporting:** Option to save a detailed text report (`report.txt`) containing the full breakdown of all allocations.

## 🛠️ Technical Architecture
This project is built using a highly modular C++ architecture, separating concerns into distinct components:
- **`memory.h/cpp`:** Defines core data structures (`Process`, `MemoryBlock`, `Result`).
- **`algorithms.h/cpp`:** Implements the logic for First Fit, Best Fit, and Worst Fit.
- **`visualizer.h/cpp`:** Handles the ASCII bar-chart rendering and statistics display.
- **`recommender.h/cpp`:** Contains the scoring logic to recommend the best algorithm.
- **`report.h/cpp`:** Manages file I/O to save the final report to disk.

## 🚀 How to Compile and Run

### Using an IDE (VS Code, Visual Studio, Code::Blocks)
1. Open the project folder in your IDE.
2. Ensure all `.cpp` and `.h` files are in the same directory.
3. Compile all `.cpp` files together:
   - **VS Code (Terminal):** `g++ main.cpp algorithms.cpp memory.cpp visualizer.cpp recommender.cpp report.cpp -o MemoryOptimizer`
   - **Visual Studio:** Add all files to a single Console Application project and press Run.
4. Run the executable.

### Using Terminal / Command Prompt
```bash
# Compile
g++ main.cpp algorithms.cpp memory.cpp visualizer.cpp recommender.cpp report.cpp -o MemoryOptimizer

# Run
./MemoryOptimizer or 
MemoryOptimizer.exe 