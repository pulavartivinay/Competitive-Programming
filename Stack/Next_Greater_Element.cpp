Question Link: https://leetcode.com/problems/next-greater-element-i/

Solution:
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_map<int, int> mp;
    stack<int> st;

    int n = nums2.size();
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && nums2[i] >= st.top()) st.pop();

        if(st.empty()) mp[nums2[i]] = -1;
        else mp[nums2[i]] = st.top();

        st.push(nums2[i]);
    }

    for(int i=0;i<nums1.size();i++)
    {
        ans.push_back(mp[nums1[i]]);
    }

    return ans;
}
