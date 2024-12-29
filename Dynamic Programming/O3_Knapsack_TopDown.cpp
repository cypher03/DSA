#include <bits/stdc++.h>
using namespace std;
// Making the memorization matrix for Knapsack without using recursion. Done by using iterative approach to fill the matrix
//  vector<vector<int>>t;
vector<vector<int>> t(101, vector<int>(1002, -1));
void mem(vector<vector<int>> t, int v, int w, vector<int> val, vector<int> wt)
{
    for (int i = 0; i < v; i++)
    {
        t[i][0] = 0;
    }
    for (int i = 0; i < w; i++)
    {
        t[0][i] = 0;
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i + 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
}

int main()
{
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    mem(t,4,8,val,wt);
    cout<<t[3][4]<<"dd"<<endl;
    return 0;
}