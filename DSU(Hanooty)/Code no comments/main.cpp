#include <iostream>

using namespace std;

class DSU {
public:
    int* parent;
    int* rank;
    int* size;

    DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        size = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }


    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unionByRank(int x, int y) {
        int root1 = find(x);
        int root2 = find(y);

        if (root1 == root2) {
            return;
        }

        if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
        } else if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else {
            parent[root1] = root2;
            rank[root2]++;
        }
    }

    void unionBySize(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return;
        }

        int sizex = size[rootX];
        int sizey = size[rootY];

        if (sizex < sizey) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }

    bool isConnect(int x1, int x2) {
        return (find(x1) == find(x2));
    }
};

int main() {
    DSU r(5);
    DSU s(5);

    r.unionByRank(2, 3);
    r.unionByRank(0, 2);
    r.unionByRank(1, 3);

    s.unionBySize(3, 4);
    s.unionBySize(2, 0);
    s.unionBySize(3, 2);

    cout << (r.isConnect(2, 2) ? "Connected" : "Not Connected") << endl;
    cout << (r.isConnect(1, 4) ? "Connected" : "Not Connected") << endl;
    cout << (r.isConnect(3, 2) ? "Connected" : "Not Connected") << endl;
    cout << (r.isConnect(4, 1) ? "Connected" : "Not Connected") << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << (s.isConnect(3, 2) ? "Connected" : "Not Connected") << endl;
    cout << (s.isConnect(1, 4) ? "Connected" : "Not Connected") << endl;
    cout << (s.isConnect(2, 0) ? "Connected" : "Not Connected") << endl;
    cout << (s.isConnect(3, 1) ? "Connected" : "Not Connected") << endl;
    return 0;
}
