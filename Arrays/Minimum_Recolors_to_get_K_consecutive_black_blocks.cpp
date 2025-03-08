Question Link: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/

Solution:
int minimumRecolors(string blocks, int k) {
    int n = blocks.size();
    int ans = INT_MAX, cnt = 0;

    for(int i=0;i<k;i++)
    {
        if(blocks[i] == 'W') cnt++;
    }
    ans = cnt;

    for(int i=k;i<n;i++)
    {
        if(blocks[i] == 'W') cnt++;
        if(blocks[i-k] == 'W') cnt--;
        ans  = min(ans, cnt);
    }

    return ans;
}
