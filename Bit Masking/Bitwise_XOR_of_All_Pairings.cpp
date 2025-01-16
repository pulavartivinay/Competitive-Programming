Question Link: https://leetcode.com/problems/bitwise-xor-of-all-pairings/

Solution:
int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int ans1 = 0, ans2 = 0;
    int n1 = nums1.size(), n2 = nums2.size();
    for(int i=0;i<n1;i++) ans1 = ans1 ^ nums1[i];
    for(int i=0;i<n2;i++) ans2 = ans2 ^ nums2[i];
    if((n1 & 1) && (n2 & 1)) return (ans1 ^ ans2);
    else if(n1 & 1) return ans2;
    else if(n2 & 1) return ans1;
    else return 0;
}
