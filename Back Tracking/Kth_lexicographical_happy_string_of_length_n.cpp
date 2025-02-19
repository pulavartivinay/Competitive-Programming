Question Link: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/

Solution:
void backTrack(string curr, vector<string> &ans, int n)
{
    int len = curr.length();
    if(len == n)
    {
        ans.push_back(curr);
        return;
    }

    char last_char = ((len != 0) ? curr[len-1] : ' ');
    char c;
    for(int i=0;i<3;i++)
    {
        c = 'a' + i;
        if(last_char != c) backTrack(curr + c, ans, n);
    }
}
string getHappyString(int n, int k) {
    vector<string> ans;
    backTrack("", ans, n);

    sort(ans.begin(), ans.end());

    if(ans.size() >= k) return ans[k-1];
    else return "";
}
