Question Link: https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1#

Solution:

vector<vector<int> > stockBuySell(vector<int> arr, int n){
    // code here
    vector<vector<int>> ans;
    int i = 0;
    while(i < n)
    {
        while(i < n-1 && arr[i] >= arr[i+1]) i++;
        if(i == n-1) return ans; // no local minima case
        int buy = i;
        i++;
        while(i < n && arr[i-1] <= arr[i]) i++;
        int sell = i-1;
        ans.push_back({buy, sell});
    }
    return ans;
}
