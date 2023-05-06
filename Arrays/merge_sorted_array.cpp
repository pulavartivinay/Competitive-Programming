Question Link: https://leetcode.com/problems/merge-sorted-array/description/

Solution:

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    if(n == 0) return;
    int i = 0, j = 0;
    while(i < m)
    {
        if(nums1[i] > nums2[j]) 
        {
            swap(nums1[i], nums2[j]);
            sort(nums2.begin(), nums2.end());
        }
        i++;
    }

    for(int i=m;i<(m+n);i++)
    {
        nums1[i] = nums2[i-m];
    }
    return;
}
