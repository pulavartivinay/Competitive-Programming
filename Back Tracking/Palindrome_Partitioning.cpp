Question Link: https://leetcode.com/problems/palindrome-partitioning/

Solution:

bool isPalindrome(string d)
{
    if(d.length() == 0) return 0;
    string f = d;
    reverse(f.begin(),f.end());
    return (f == d) ? 1 : 0;
}
void helper(vector<vector<string>>& ans, vector<string> li, string s, int a, int b)
{
    if(a >= b) 
    {
        ans.push_back(li);
        return;
    }
    for(int i=a;i<b;i++)
    {
        string g = s.substr(a, i-a+1);
        if(isPalindrome(g))
        {
            li.push_back(g);
            helper(ans, li, s, i+1, b);
            li.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) 
{
    vector<vector<string>> ans;
    int n = s.length();
    vector<string> li;
    helper(ans, li, s, 0, n);
    return ans;
}
