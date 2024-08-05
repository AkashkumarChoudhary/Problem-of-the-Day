class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> s;      
        unordered_set<string> d; 

        for (const string& i : arr) {
            if (s.count(i)) {
                d.insert(i); 
            } else {
                s.insert(i); 
            }
        }

        int c = 0;
        for (const string& i : arr) {
            if (s.count(i) && !d.count(i)) { 
                c++;
                if (c == k) {
                    return i; 
                }
            }
        }

        return ""; 
    }
};
