Question Link: https://leetcode.com/problems/count-and-say/description/

Solution:
string helper(string s)
{
    string ans = "";
    int n = s.length();
    int cnt = 1;
    for(int i=1;i<n;i++)
    {
        if(s[i] == s[i-1]) cnt++;
        else
        {
            ans += to_string(cnt);
            ans += s[i-1];
            cnt = 1;
        }
    }

    ans += to_string(cnt);
    ans += s[n-1];

    return ans;
}
string countAndSay(int n) {
    string ans = "1";

    for(int i=1;i<n;i++)
    {
        ans = helper(ans);
    }

    return ans;
}
