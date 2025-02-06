Question Link: https://leetcode.com/problems/unique-number-of-occurrences/description/

Solution:
bool uniqueOccurrences(vector<int>& arr) {
    int n = arr.size();

    unordered_map<int, int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }

    unordered_map<int, bool> mpp;
    for(auto k:mp)
    {
        if(mpp[k.second]) return false;
        mpp[k.second] = true;
    }

    return true;
}
