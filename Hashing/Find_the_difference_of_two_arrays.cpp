Question Link: https://leetcode.com/problems/find-the-difference-of-two-arrays/description/

Solution:
vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> ans(2);
    int n1 = nums1.size(), n2 = nums2.size();

    unordered_map<int, int> mp1, mp2;
    for(int i=0;i<n1;i++) mp1[nums1[i]]++;
    for(int i=0;i<n2;i++) mp2[nums2[i]]++;

    for(int i=0;i<n1;i++)
    {
        if(mp2[nums1[i]] != 0) continue;
        mp1[nums1[i]]--;

        if(mp1[nums1[i]] == 0) ans[0].push_back(nums1[i]);
    }

    for(int i=0;i<n2;i++)
    {
        if(mp1[nums2[i]] != 0) continue;
        mp2[nums2[i]]--;

        if(mp2[nums2[i]] == 0) ans[1].push_back(nums2[i]);
    }

    return ans;
}
