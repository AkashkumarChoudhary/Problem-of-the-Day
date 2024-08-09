int Maximize(std::vector<int> &arr) {
    // Sort the array in ascending order
    std::sort(arr.begin(), arr.end());
    
    long long result = 0;
    int n = arr.size();
    
    // Calculate the sum of arr[i] * i
    for (int i = 0; i < n; ++i) {
        result = (result + (long long)arr[i] * i) % MOD;
    }
    
    return result;
}