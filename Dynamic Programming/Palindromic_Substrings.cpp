Question Link: https://leetcode.com/problems/palindromic-substrings/description/

Solution:
int countSubstrings(string s) {
    int n = s.length();
    int cnt = 0, left = 0, right = 0;

    for(int c=0;c<n;c++)
    {
        // odd palindromes
        left = c-1, right = c+1;
        cnt++;
        while(left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
            cnt++;
        }

        // even palindromes
        left = c, right = c+1;
        while(left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
            cnt++;
        }
    }

    return cnt;
}
