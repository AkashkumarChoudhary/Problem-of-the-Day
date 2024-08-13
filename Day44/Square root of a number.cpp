 int floorSqrt(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    int start = 1, end = n, ans = 0;
    while (start <= end) {
        int mid = (start + end) / 2;

        long long midSquared = (long long)mid* mid;
        if (midSquared == n) {
            return mid;
        }

       
        if (midSquared < n) {
            start = mid + 1;
            ans = mid;  
        } else {
             end = mid - 1;
        }
    }
    return ans;
}