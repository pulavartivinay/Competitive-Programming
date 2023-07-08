Question Link: https://leetcode.com/problems/license-key-formatting/description/

Solution:
string licenseKeyFormatting(string s, int k) {
    string ans = "";
    int n = s.length();
    int cnt = 0;
    for(int i=n-1;i>=0;i--)
    {
        if(cnt == k)
        {
            cnt = 0;
            ans += '-';
        }
        if(s[i] != '-') 
        {
            cnt++;
            ans += toupper(s[i]);
        }
        
    }
    reverse(ans.begin(), ans.end());
    n = ans.length();
    if(ans[0] == '-') return (ans.substr(1, n));
    return ans;
}
