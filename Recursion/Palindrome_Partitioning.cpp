Question Link: https://leetcode.com/problems/palindrome-partitioning/description/

Solution:
bool isPalindrome(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return (s == t);
}
void helper(int k, string& s, vector<string> curr, vector<vector<string>>& ans)
{
    if(k == s.length())
    {
        ans.push_back(curr);
        return;
    }

    string t = "";
    for(int i=k;i<s.length();i++)
    {
        t += s[i];
        if(isPalindrome(t))
        {
            curr.push_back(t);
            helper(i+1, s, curr, ans);
            curr.pop_back();
        }
    }

    return;
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> curr;
    helper(0, s, curr, ans);

    return ans;
}
