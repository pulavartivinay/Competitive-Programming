Question Link: https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string1956/1

Solution:

string longestPalindrome(string S)
{
    // code here 
    int n = S.length();
    int start = 0;
    int count = 0;
    for(int i=0;i<n;i++)
    {
        // odd palindromes
        int left = i-1;
        int right = i+1;
        int c = 1;
        while(left>=0 && right<=n-1 && S[left] == S[right])
        {
            c = c+2;
            left--;
            right++;
        }
        if(c>count)
        {
            if(left>=0) start = left+1;
            count = c;
        }
        c = 0;

        // even palindromes
        left = i;
        right = i+1;
        while(left>=0 && right<=n-1 && S[left] == S[right])
        {
            c = c+2;
            left--;
            right++;
        }
        if(c>count) 
        {
            if(left>=0) start = left+1;
            count = c;
        }
        c = 0;
    }
    string ans = "";
    for(int i=start;i<(start+count);i++)
    {
        ans += S[i];
    }
    return ans;
}
