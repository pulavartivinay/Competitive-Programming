Question Link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

Solution:
int maxLen(vector<int>&A, int n)
{   
    // Your code here
    unordered_map<int,int> mp;
    int sum = 0;
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        sum += A[i-1];
        if(sum != 0 && mp[sum] == 0) 
        {
            mp[sum] = i;
            continue;
        }
        
        ans = max(ans, i-mp[sum]);
    }
    return ans;
}
