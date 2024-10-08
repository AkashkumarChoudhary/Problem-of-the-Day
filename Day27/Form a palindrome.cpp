     int countMin(string str) {
    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill the table
    for (int gap = 1; gap < n; ++gap) {
        for (int l = 0, h = gap; h < n; ++l, ++h) {
            if (str[l] == str[h]) {
                dp[l][h] = dp[l + 1][h - 1];
            } else {
                dp[l][h] = min(dp[l][h - 1], dp[l + 1][h]) + 1;
            }
        }
    }

    // The result is in dp[0][n-1]
    return dp[0][n-1];
}