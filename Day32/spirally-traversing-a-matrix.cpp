vector<int> spirallyTraverse(vector<vector<int>> &matrix) {
    vector<int> result;
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    int leftBoundary = 0, topBoundary = 0;
    int bottomBoundary = numRows - 1, rightBoundary = numCols - 1;

    while (leftBoundary <= rightBoundary && topBoundary <= bottomBoundary) {
        for (int col = leftBoundary; col <= rightBoundary; col++)
            result.push_back(matrix[topBoundary][col]);
        topBoundary++;

        for (int row = topBoundary; row <= bottomBoundary; row++)
            result.push_back(matrix[row][rightBoundary]);
        rightBoundary--;

        if (topBoundary <= bottomBoundary) {
            for (int col = rightBoundary; col >= leftBoundary; col--)
                result.push_back(matrix[bottomBoundary][col]);
            bottomBoundary--;
        }

        if (leftBoundary <= rightBoundary) {
            for (int row = bottomBoundary; row >= topBoundary; row--)
                result.push_back(matrix[row][leftBoundary]);
            leftBoundary++;
        }
    }

    return result;
}