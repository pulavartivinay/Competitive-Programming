Question: https://practice.geeksforgeeks.org/problems/subset-sums2234/1

Solution:

void recur(int a, int b, int t_sum, vector<int> arr, vector<int>& ans)
{
    if(a < b)
    {
        //element is present
        recur(a+1,b,t_sum+arr[a],arr,ans);
        //element is not present
        recur(a+1,b,t_sum,arr,ans);
    }
    else ans.push_back(t_sum);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    vector<int> ans;
    int t_sum = 0;
    recur(0,N,t_sum,arr,ans);
    sort(ans.begin(), ans.end());
    return ans;
}
