Question Link: https://www.interviewbit.com/problems/subarray-with-given-xor/

Solution:
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int ans = 0;
    int x = 0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        x ^= A[i];
        if(x == B) ans++;
        ans += mp[x^B];
        
        mp[x]++;
    }
    return ans;
}
