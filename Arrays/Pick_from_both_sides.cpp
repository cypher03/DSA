//interviewbit
int Solution::solve(vector<int> &a, int b) {
       int n=a.size();
    vector<int>prefix(b),suffix(b);
    int pre=0,suf=0;
    for(int i=0; i<b; i++){
        pre+=a[i];
        prefix[i]=pre;
        suf+=a[n-i-1];
        suffix[i]=suf;
    }
    int ans=max(prefix[b-1],suffix[b-1]);
    for(int i=0; i<b-1; i++){
        ans=max(ans,prefix[i]+suffix[b-i-2]);
    }
    return ans;
}
