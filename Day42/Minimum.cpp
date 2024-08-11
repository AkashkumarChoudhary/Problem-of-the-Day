 

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Function to check if the grid is connected
        auto isConnected = [&](vector<vector<int>>& g) {
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            int landCount = 0;
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    if (g[r][c] == 1) {
                        ++landCount;
                    }
                }
            }
            if (landCount == 0) return false; // No land at all
            
            int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            auto dfs = [&](int r, int c, auto&& dfs) -> void {
                visited[r][c] = true;
                for (auto& dir : directions) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && g[nr][nc] == 1 && !visited[nr][nc]) {
                        dfs(nr, nc, dfs);
                    }
                }
            };
            
            // Find the first land cell and start DFS
            bool found = false;
            for (int r = 0; r < rows && !found; ++r) {
                for (int c = 0; c < cols && !found; ++c) {
                    if (grid[r][c] == 1) {
                        dfs(r, c, dfs);
                        found = true;
                    }
                }
            }
            
            // Check if all land cells are visited
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    if (grid[r][c] == 1 && !visited[r][c]) {
                        return false;
                    }
                }
            }
            return true;
        };
        
        // Check if the grid is already disconnected
        if (!isConnected(grid)) return 0;
        
        // Try removing one land cell
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    grid[r][c] = 0;
                    if (!isConnected(grid)) return 1;
                    grid[r][c] = 1;
                }
            }
        }
        
        // Try removing two land cells
        for (int r1 = 0; r1 < rows; ++r1) {
            for (int c1 = 0; c1 < cols; ++c1) {
                if (grid[r1][c1] == 1) {
                    grid[r1][c1] = 0;
                    for (int r2 = 0; r2 < rows; ++r2) {
                        for (int c2 = 0; c2 < cols; ++c2) {
                            if (grid[r2][c2] == 1) {
                                grid[r2][c2] = 0;
                                if (!isConnected(grid)) return 2;
                                grid[r2][c2] = 1;
                            }
                        }
                    }
                    grid[r1][c1] = 1;
                }
            }
        }
        
        return 2; // If we can't disconnect the grid by removing one or two cells, it will take at least 2 days
    }
};
