class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        // Function to check if a 3x3 grid is a magic square
        auto isMagic = [&](int r, int c) {
            unordered_set<int> uniqueNumbers;
            for (int i = r; i < r + 3; ++i) {
                for (int j = c; j < c + 3; ++j) {
                    if (grid[i][j] < 1 || grid[i][j] > 9 || !uniqueNumbers.insert(grid[i][j]).second) {
                        return false;
                    }
                }
            }
            int sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];
            return (grid[r][c] + grid[r][c + 1] + grid[r][c + 2] == sum &&
                    grid[r + 1][c] + grid[r + 1][c + 1] + grid[r + 1][c + 2] == sum &&
                    grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2] == sum &&
                    grid[r][c] + grid[r + 1][c] + grid[r + 2][c] == sum &&
                    grid[r][c + 1] + grid[r + 1][c + 1] + grid[r + 2][c + 1] == sum &&
                    grid[r][c + 2] + grid[r + 1][c + 2] + grid[r + 2][c + 2] == sum &&
                    grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] == sum &&
                    grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] == sum);
        };
         for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 0; j <= cols - 3; ++j) {
                if (isMagic(i, j)) {
                    ++count;
                }
            }
        }

        return count;
    }
};