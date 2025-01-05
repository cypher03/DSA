int Solution::solve(vector<int> &A) {
    int n = A.size();
    if (n < 3) return 0; // If there are less than 3 elements, no triplet is possible

    // Suffix array to store the maximum element to the right
    vector<int> suffix_max(n);
    suffix_max[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffix_max[i] = max(suffix_max[i + 1], A[i]);
    }

    set<int> seen; // Set to store elements seen so far
    int max_sum = 0;

    seen.insert(A[0]); // Add the first element to the set
    for (int j = 1; j < n - 1; j++) {
        if (suffix_max[j + 1] > A[j]) { // Check if there is a valid k
            // Find the largest element smaller than A[j] from the set
            auto it = seen.lower_bound(A[j]);
            if (it != seen.begin()) {
                --it; // Move to the largest element smaller than A[j]
                int left = *it;
                int right = suffix_max[j + 1];
                max_sum = max(max_sum, left + A[j] + right);
            }
        }
        seen.insert(A[j]); // Add the current element to the set
    }

    return max_sum;
}
