Question Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

Solution:
int strStr(string haystack, string needle) {
    int m = haystack.length();
    int n = needle.length();

    for(int i=0;i<=(m-n);i++)
    {
        if(haystack[i] == needle[0])
        {
            int j;
            for(j=0;j<n;j++)
            {
                if(haystack[i+j] != needle[j]) break;
            }
            if(j == n) return i;
        }
    }
    return -1;
}
