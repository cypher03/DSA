#include<bits/stdc++.h>
using namespace std;
    bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<bool>> dp(n+1,vector<bool>(target+1));
        for(int i=0; i<target+1; i++){
            dp[0][i]=false;
        }
        for(int i=0; i<n+1; i++){
            dp[i][0]=true;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<target+1; j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
int main(){
    
    return 0;
}