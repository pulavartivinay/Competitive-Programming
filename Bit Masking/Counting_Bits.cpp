Question Link: https://leetcode.com/problems/counting-bits/

Solution:

vector<int> countBits(int n) 
{
    vector<int> ans;
    for(int i=0;i<=n;i++)
    {
        int count = 0;
        for(int j=0;j<32;j++)
        {
            if(i & (1 << j)) count++;
        }
        ans.push_back(count);
    }
    return ans;
}
