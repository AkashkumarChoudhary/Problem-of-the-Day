class Solution {
public:
    int minimumDeletions(string s) {
        int length = s.size();
        int dp[length + 1];  
        memset(dp, 0, sizeof(dp));
        int countB = 0;  
        for (int i = 1; i <= length; ++i) {
            if (s[i - 1] == 'b') {
                dp[i] = dp[i - 1];  
                ++countB;  
            } else {
                dp[i] = min(dp[i - 1] + 1, countB);  
            }
        }
        return dp[length];
    }
};
