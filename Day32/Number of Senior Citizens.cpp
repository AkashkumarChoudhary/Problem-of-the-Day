class Solution {
public:
    int countSeniors(vector<string>& details) {
        int main = 0;
        for (auto& x : details) {
            int age = stoi(x.substr(11, 2));
            main += age > 60;
        }
        return main;
    }
};