Question Link: https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1

Solution:

int maxSubstring(string S)
{
    // Your code goes here
    int n = S.length();
    vector<int> store;
    for(int i=0;i<n;i++)
    {
        if(S[i] == '0') store.push_back(1);
        else store.push_back(-1);
    }
    int ans = INT_MIN;
    int curr = 0;
    for(int i=0;i<n;i++)
    {
        curr = max(store[i], curr + store[i]);
        ans = max(ans, curr);
    }
    return ans;
}
