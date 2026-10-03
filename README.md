# Disjoint Set Union (DSU) Implementation

An efficient C++ implementation of the **Disjoint Set Union (DSU)** (or Union-Find) data structure. This project demonstrates near-constant time complexity operations using **Path Compression**, **Union by Rank**, and **Union by Size** optimizations.

## Core Features & Operations

* **Path Compression (`find`):**
  * Recursively finds the representative (root) of a set while flattening the structure of the tree to accelerate future queries.

* **Union by Rank (`unionByRank`):**
  * Connects two sets by attaching the tree with smaller depth (rank) under the root of the tree with larger depth[cite: 22].

* **Union by Size (`unionBySize`):**
  * Connects two sets by attaching the smaller set under the root of the larger set and updating the total element count[cite: 22].

* **Connectivity Check (`isConnect`):**
  * Determines whether two elements belong to the same set/component[cite: 22].

## Data Structures & Memory Management

The `DSU` class dynamically allocates memory for tracking element pointers[cite: 22]:
* **`parent` (int*):** Stores the parent index for each element (initially pointing to itself)[cite: 22].
* **`rank` (int*):** Tracks the depth of each tree (initialized to 0)[cite: 22].
* **`size` (int*):** Tracks the total number of elements in each set (initialized to 1)[cite: 22].

## Getting Started

### Prerequisites

* Any standard C++ compiler supporting standard dynamic memory allocation (`g++`, `clang++`, or MSVC)[cite: 22].

### Compilation & Execution

```bash
# 1. Clone the repository
git clone [https://github.com/your-username/DSU-Data-Structure.git](https://github.com/your-username/DSU-Data-Structure.git)
cd DSU-Data-Structure

# 2. Compile the source code
g++ main.cpp -o dsu

# 3. Run the executable
./dsu

// Create a DSU instance for 5 elements (0 to 4)
DSU dsu(5);

// Merge sets using Union by Rank or Union by Size
dsu.unionByRank(2, 3);
dsu.unionByRank(0, 2);

// Check if elements are connected
if (dsu.isConnect(0, 3)) {
    cout << "Connected" << endl;
}
