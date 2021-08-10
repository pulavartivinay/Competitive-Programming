Question Link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3876/

Solution:

int minFlipsMonoIncr(string s) 
{
    int n = s.length();
    vector<char> need(n,'1');
    int ans = INT_MAX;
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(need[i] != s[i]) count++;
    }
    ans = min(ans,count);
    for(int i=0;i<n;i++)
    {
        need[i] = '0';
        if(need[i] != s[i]) count++;
        else count--;
        ans = min(ans,count);
    }
    return ans;
}
