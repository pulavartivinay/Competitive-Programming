Question Link: https://leetcode.com/problems/longest-common-prefix/description/

Solution:
string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    string ans = "";
    int len = INT_MAX;
    for(int i=0;i<n;i++)
    {
        len = min(len, (int) strs[i].length());
    }
    int cnt = 0;
    while(cnt < len)
    {
        char ch = strs[0][cnt];
        for(int i=1;i<n;i++)
        {
            if(ch != strs[i][cnt]) return ans;
        }
        ans += ch;
        cnt++;
    }
    return ans;
}
