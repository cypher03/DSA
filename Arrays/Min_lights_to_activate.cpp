int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int i = 0, count = 0;

    while (i < n) {
        // Find the rightmost bulb that can light the current position
        int j = min(i + B - 1, n - 1);
        while (j >= max(i - B + 1, 0) && A[j] == 0) {
            j--;
        }
        
        // If no suitable bulb is found, return -1
        if (j < max(i - B + 1, 0)) {
            return -1;
        }

        // Turn on the bulb at position j
        count++;
        
        // Move to the next unlit position
        i = j + B;
    }

    return count;
}

