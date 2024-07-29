    int rowWithMax1s(vector<vector<int>> &matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    int colIndex;
    int maxCount = 0;
    int maxOnes = INT_MIN;
    int resultRow = -1;

    for (int rowIndex = 0; rowIndex < numRows; rowIndex++) {
        colIndex = 0;
        while (colIndex < numCols && matrix[rowIndex][colIndex] != 1) {
            colIndex++;
        }
        if (numCols - colIndex > maxOnes && colIndex != numCols) {
            maxOnes = numCols - colIndex;
            resultRow = rowIndex;
        }
    }
    return resultRow;
}