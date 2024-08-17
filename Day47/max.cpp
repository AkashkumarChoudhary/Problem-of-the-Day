class Solution {
public:
    

int maxDistance(std::vector<std::vector<int>>& arrays) {
    int min_val = arrays[0].front();
    int max_val = arrays[0].back();
    int max_distance = 0;

    for (int i = 1; i < arrays.size(); ++i) {
         max_distance = std::max(max_distance, std::abs(arrays[i].back() - min_val));
        max_distance = std::max(max_distance, std::abs(max_val - arrays[i].front()));
        min_val = std::min(min_val, arrays[i].front());
        max_val = std::max(max_val, arrays[i].back());
    }

    return max_distance;
}
};
// day 48