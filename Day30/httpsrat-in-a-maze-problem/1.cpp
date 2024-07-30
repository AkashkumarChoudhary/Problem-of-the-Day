void findPathsHelper(int currentRow, int currentCol, vector<vector<int>> &matrix, int size, string currentPath, vector<string> &allPaths, vector<vector<int>> &visited) {
        if (currentRow == 0 && currentCol == 0) {
            allPaths.push_back(currentPath);
            return;
        }
        
        string directions = "RDLU";
        int rowOffsets[] = {0, -1, 0, 1};
        int colOffsets[] = {-1, 0, 1, 0};
        
        for (int i = 0; i < 4; i++) {
            int newRow = currentRow + rowOffsets[i];
            int newCol = currentCol + colOffsets[i];
            
            if (newRow >= 0 && newCol >= 0 && newRow < size && newCol < size && matrix[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                visited[newRow][newCol] = 1;
                findPathsHelper(newRow, newCol, matrix, size, directions[i] + currentPath, allPaths, visited);
                visited[newRow][newCol] = 0;
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &matrix) {
        int size = matrix.size();
        vector<string> allPaths;
        
        vector<vector<int>> visited(size, vector<int>(size, 0));
        
        if (!matrix[size - 1][size - 1]) return allPaths;
        
        visited[size - 1][size - 1] = 1;
        
        findPathsHelper(size - 1, size - 1, matrix, size, "", allPaths, visited);
        
        return allPaths;
    }