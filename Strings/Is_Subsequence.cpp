Question Link: https://leetcode.com/problems/is-subsequence/description/

Solution:
bool isSubsequence(string s, string t) {
    if(s == "") return true;
    if(t == "") return false;

    int n = s.length();
    int m = t.length();

    int i = 0;
    for(int j=0;j<m;j++)
    {
        if(s[i] == t[j]) i++;

        if(i == n) return true;
    }

    return false;
}
