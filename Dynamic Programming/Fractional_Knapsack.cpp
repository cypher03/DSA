#include<bits/stdc++.h>
using namespace std;

int fractional_knapsack(vector<int> wt, vector<int> val, int w,int n){
    if(n==0 || w==0){
        return 0;
    }
    if(wt[n-1] <= w){
        return max(val[n-1]+fractional_knapsack(wt,val,w-wt[n-1],n-1), fractional_knapsack(wt,val,w,n-1));
    }
    else if(wt[n-1]>w){
        return fractional_knapsack(wt,val,w,n-1);
    }
}

int main(){
    vector<int>wt={1,3,4,5}, val={1,4,5,7};
    int w=7, n=wt.size();

    cout<<fractional_knapsack(wt,val,w,n);
    return 0;
}