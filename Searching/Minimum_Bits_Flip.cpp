Question Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

Solution:
int minBitFlips(int start, int goal) {
    int ans = 0;
    for(int i=0;i<32;i++)
    {
        int start_bit = (start & (1 << i));
        int end_bit = (goal & (1 << i));
        if(start_bit != end_bit) ans++;
    }

    return ans;
}
