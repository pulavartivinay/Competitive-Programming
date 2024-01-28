Question Link: https://www.codingninjas.com/studio/problems/920336?topList=striver-sde-sheet-problems&leftPanelTabValue=PROBLEM

Solution:
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    vector<int> ans;
    unordered_map<int,int> mp;

    int n = arr.size(), cnt = 0;
    for(int i=0;i<k;i++)
    {
        mp[arr[i]]++;
    }
    cnt = mp.size();
    ans.push_back(cnt);
    for(int i=k;i<n;i++)
    {
        if(arr[i] == arr[i-k])
        {
            ans.push_back(cnt);
            continue;
        }
        mp[arr[i]]++;
        mp[arr[i-k]]--;

        if(mp[arr[i]] == 1) cnt++;
        if(mp[arr[i-k]] == 0) cnt--;
        ans.push_back(cnt);
    }

    return ans;
}
