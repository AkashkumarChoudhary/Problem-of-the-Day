int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
    int n = arr1.size();
    if (n == 0) return 0;

    int low = 0, high = n;

    while (low <= high) {
        int partition1 = (low + high) / 2;
        int partition2 = n - partition1;

        int maxLeft1 = (partition1 == 0) ? INT_MIN : arr1[partition1 - 1];
        int minRight1 = (partition1 == n) ? INT_MAX : arr1[partition1];

        int maxLeft2 = (partition2 == 0) ? INT_MIN : arr2[partition2 - 1];
        int minRight2 = (partition2 == n) ? INT_MAX : arr2[partition2];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            return max(maxLeft1, maxLeft2) + min(minRight1, minRight2);
        } else if (maxLeft1 > minRight2) {
            high = partition1 - 1;
        } else {
            low = partition1 + 1;
        }
    }

    throw invalid_argument("Input arrays are not sorted or of the same size.");
}