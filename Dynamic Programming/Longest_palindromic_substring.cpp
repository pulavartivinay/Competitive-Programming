Question Link: https://leetcode.com/problems/longest-palindromic-substring/description/

Solution:
string longestPalindrome(string s) {
    int n = s.length();

    int left = 0, right = 0, length = 1, start = 0;
    for(int c=0;c<n;c++)
    {
        // odd palindromes
        left = c-1, right = c+1;
        while(left >= 0 && right < n && s[left] == s[right])
        {
            length = max(length, right - left + 1);
            if(length == (right - left + 1)) start = left;
            left--;
            right++;
        }

        // even palidromes
        left = c, right = c+1;
        while(left >= 0 && right < n && s[left] == s[right])
        {
            length = max(length, right - left + 1);
            if(length == (right - left + 1)) start = left;
            left--;
            right++;
        }
    }

    string ans = "";
    for(int i=start;i<(start+length);i++) ans += s[i];

    return ans;
}
