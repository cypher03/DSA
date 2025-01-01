vector<int> Solution::spiralOrder(const vector<vector<int>> &a) {
    int m = a.size();
    if (m == 0) return {};
    int n = a[0].size();

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    vector<int> ans;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int i = left; i <= right; i++) {
            ans.push_back(a[top][i]);
        }
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++) {
            ans.push_back(a[i][right]);
        }
        right--;

        if (top <= bottom) {
            // Traverse from right to left
            for (int i = right; i >= left; i--) {
                ans.push_back(a[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            // Traverse from bottom to top
            for (int i = bottom; i >= top; i--) {
                ans.push_back(a[i][left]);
            }
            left++;
        }
    }

    return ans;
}
