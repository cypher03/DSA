//interviewbit
string multiplyStrings(string num1, string num2) {
    int n = num1.size(), m = num2.size();
    vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string ans;
    for (int num : result) {
        if (!(ans.empty() && num == 0)) { // Skip leading zeros
            ans.push_back(num + '0');
        }
    }

    return ans.empty() ? "0" : ans;
}

string factorial(int a) {
    string result = "1";
    for (int i = 2; i <= a; i++) {
        result = multiplyStrings(result, to_string(i));
    }
    return result;
}

string Solution::solve(int a) {
    return factorial(a);
}