Question Link: https://leetcode.com/problems/merge-sorted-array/description/

Solution:
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(n == 0) return;
    int i = m-1, j = n-1, pos = (n+m-1);
    while(i >= 0 && j >= 0)
    {
        if(nums1[i] <= nums2[j]) 
        {
            swap(nums2[j], nums1[pos]);
            j--;
        }
        else
        {
            swap(nums1[i], nums1[pos]);
            i--;
        }
        pos--;
    }
    while(j >= 0)
    {
        swap(nums2[j], nums1[pos]);
        j--;
        pos--;
    }
    return;
}
