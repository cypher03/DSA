vector<int> Solution::maxset(vector<int> &a) {
    int n = a.size();
    vector<int> ans, temp;
    long long maxSum = 0, tempSum = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            temp.push_back(a[i]);
            tempSum += a[i];
        } else {
            if (tempSum > maxSum || 
                (tempSum == maxSum && temp.size() > ans.size())) {
                ans = temp;
                maxSum = tempSum;
            }
            temp.clear();
            tempSum = 0;
        }
    }

    // Check the last subarray
    if (tempSum > maxSum || 
        (tempSum == maxSum && temp.size() > ans.size())) {
        ans = temp;
    }

    return ans;
}
