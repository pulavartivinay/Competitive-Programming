Question Link: https://leetcode.com/problems/longest-nice-subarray/

Solution:
void updateFreq(vector<int>& freq, int num)
{
    for(int i=0;i<32;i++) if(num & (1 << i)) freq[i]++;
}
bool isPossible(vector<int>& freq)
{
    for(int i=0;i<32;i++) if(freq[i] > 1) return false;
    return true;
}
void removeFreq(vector<int>& freq, int num)
{
    for(int i=0;i<32;i++) if(num & (1 << i)) freq[i]--;
}
int longestNiceSubarray(vector<int>& nums) {
    int n = nums.size();
    int ans = 1;

    vector<int> freq(32, 0);
    updateFreq(freq, nums[0]);

    int i = 0, j = 1;
    while(i < j && j < n)
    {
        updateFreq(freq, nums[j]);
        while(i < j && !isPossible(freq))
        {
            removeFreq(freq, nums[i]);
            i++;
        }
        ans = max(ans, j-i+1);
        j++;
    }

    return ans;
}
