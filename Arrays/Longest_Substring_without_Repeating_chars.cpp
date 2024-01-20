Question Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Solution:
int lengthOfLongestSubstring(string s) {
    long long int n = s.size();
    if(n == 0) return 0;

    long long int ans = 0;
    unordered_map<char, int> mp;

    long long int i=0,j=0;
    while(j < n)
    {
        if(mp[s[j]] == 0) {
            mp[s[j]]++;
            j++;
        } else {
            ans = max(ans, j-i);
            while(s[i] != s[j])
            {
                mp[s[i]]--;
                i++;
            }
            mp[s[i]]--;
            i++;
        }
    }
    ans = max(ans, j-i);
    
    return ans;
}
