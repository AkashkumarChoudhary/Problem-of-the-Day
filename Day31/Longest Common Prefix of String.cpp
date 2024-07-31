string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "-1";

        // Find the minimum length string in the array
        int minLen = strs[0].length();
        for (const string& str : strs) {
            if (str.length() < minLen) {
                minLen = str.length();
            }
        }

        // Find the longest common prefix
        string ans = strs[0].substr(0, minLen);
        for (int i = 0; i < minLen; ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != ans[i]) {
                    if (i == 0) return "-1"; // No common prefix
                    return ans.substr(0, i);
                }
            }
        }

        return ans;
    }