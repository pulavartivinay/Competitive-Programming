Question Link: https://practice.geeksforgeeks.org/problems/large-factorial4721/1/

Solution:

vector<long long> factorial(vector<long long> a, int n) {
    vector<long long int> ans;
    vector<long long int> store(a.begin(), a.end());
    sort(store.begin(), store.end());
    long long int hi = store[n-1];
    vector<long long int> dp (hi, 1);
    dp.push_back(1);
    dp.push_back(1);
    long long int mod = pow(10,9) + 7;
    for(int i=2;i<=hi;i++)
    {
        dp[i] = (i*dp[i-1])%mod;
    }
    for(int i=0;i<n;i++)
    {
        ans.push_back(dp[a[i]]%mod);
    }
    return ans;
}
