//interviewbit
int Solution::coverPoints(vector<int> &a, vector<int> &b) {
    int n=a.size();
    int ans=0;
    for(int i=1; i<n; i++){
        int x=abs(a[i]-a[i-1]);
        int y=abs(b[i]-b[i-1]);
        ans+=min(x,y)+abs(x-y);
    }
    return ans;
}
