class Solution {
public:
   
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int size = 4 * n * n;
        parent.resize(size);
        iota(parent.begin(), parent.end(), 0); // Initialize union-find structure

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                int base = 4 * (r * n + c);
                char val = grid[r][c];
                if (val == '/') {
                    unionSets(base + 0, base + 3);
                    unionSets(base + 1, base + 2);
                } else if (val == '\\') {
                    unionSets(base + 0, base + 1);
                    unionSets(base + 2, base + 3);
                } else {
                    unionSets(base + 0, base + 1);
                    unionSets(base + 1, base + 2);
                    unionSets(base + 2, base + 3);
                }

                // Union with right cell
                if (c + 1 < n) {
                    unionSets(base + 1, base + 4 + 3);
                }
                // Union with bottom cell
                if (r + 1 < n) {
                    unionSets(base + 2, base + 4 * n + 0);
                }
            }
        }

        int regions = 0;
        for (int i = 0; i < size; ++i) {
            if (find(i) == i) {
                ++regions;
            }
        }
        return regions;
    }

private:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }


};