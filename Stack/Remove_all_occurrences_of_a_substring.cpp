Question Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

Solution:
string removeOccurrences(string s, string part) {
    int n = s.length(), m = part.length();
    string ans = "";

    for(int i=0;i<n;i++)
    {
        ans += s[i];
        if(ans.length() >= m && ans.substr(ans.length() - m) == part)
        {
            ans.erase(ans.length() - m);
        }
    }

    return ans;
}
