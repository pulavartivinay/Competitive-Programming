Question Link: https://leetcode.com/problems/longest-palindromic-substring/description/

Solution:
string longestPalindrome(string s) {
    int n = s.length();
    int ans = 1, start = 0;
    for(int i=0;i<n;i++)
    {
        // odd palindromes
        int left = i-1, right = i+1;
        while(left >= 0 && right < n && s[left] == s[right])
        {
            if(right - left + 1 > ans) start = left;
            ans = max(ans, right - left + 1);
            left--;
            right++;
        }

        // even palindromes
        left = i, right = i+1;
        while(left >= 0 && right < n && s[left] == s[right])
        {
            if(right - left + 1 > ans) start = left;
            ans = max(ans, right - left + 1);
            left--;
            right++;
        }
    }
    string s_ans = "";
    for(int i=start;i<(start+ans);i++)
    {
        s_ans += s[i];
    }
    return s_ans;
}
