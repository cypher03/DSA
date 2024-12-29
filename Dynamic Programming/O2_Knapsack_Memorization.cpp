#include<bits/stdc++.h>
using namespace std;
int static t[102][1002];


int fractional_knapsack(vector<int> wt, vector<int> val, int w,int n){
    if(n==0 || w==0){
        return 0;
    }
    if(t[n][w]!=-1){
        return t[n][w];
    }
    if(wt[n-1] <= w){
        t[n][w]=max(val[n-1]+fractional_knapsack(wt,val,w-wt[n-1],n-1), fractional_knapsack(wt,val,w,n-1));
        return t[n][w];
    }
    else if(wt[n-1]>w){
        t[n][w]=fractional_knapsack(wt,val,w,n-1);
        return t[n][w];
    }
}

int main(){
    memset(t,-1,sizeof(t));
    vector<int>wt={1,3,4,5}, val={1,4,5,7};
    int w=7, n=wt.size();

    cout<<fractional_knapsack(wt,val,w,n);
    return 0;
}