Question Link: https://practice.geeksforgeeks.org/problems/positive-negative-pair5209/1

Solution:

vector <int> findPairs(int arr[], int n) 
{
    // code here
    vector<int> ans;
    unordered_map<int, int> m;
    for(int i=0;i<n;i++)
    {
        if(m[-1*arr[i]] > 0)
        {
            ans.push_back(-abs(arr[i]));
            ans.push_back(abs(arr[i]));
            m[-1*arr[i]]--;
        }
        m[arr[i]]++;
    }
    return ans;
}
