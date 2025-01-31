class DisjointSet {
    vector<int> rank, size, parent;

public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;
        if (size[pu] >= size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }

    int getSize(int node) {
        return size[findUPar(node)];
    }
};

class Solution {
    vector<int> rows = {0, 0, 1, -1};
    vector<int> columns = {1, -1, 0, 0};

public:
    int largestIsland(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        DisjointSet ds(m * n);
        
        // Step 1: Connect existing 1s using Disjoint Set
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + rows[k];
                        int y = j + columns[k];
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                            ds.unionBySize(i * n + j, x * n + y);
                        }
                    }
                }
            }
        }

        // Step 2: Find the maximum island size before any modification
        int maxSize = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    maxSize = max(maxSize, ds.getSize(i * n + j));
                }
            }
        }

        // Step 3: Try changing each 0 to 1 and check the new island size
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_map<int, int> connectedComponents;
                    int newSize = 1; // Counting the flipped 0 itself

                    for (int k = 0; k < 4; k++) {
                        int x = i + rows[k];
                        int y = j + columns[k];

                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                            int parent = ds.findUPar(x * n + y);
                            if (connectedComponents.find(parent) == connectedComponents.end()) {
                                connectedComponents[parent] = ds.getSize(parent);
                                newSize += ds.getSize(parent);
                            }
                        }
                    }
                    maxSize = max(maxSize, newSize);
                }
            }
        }

        return maxSize;
    }
};