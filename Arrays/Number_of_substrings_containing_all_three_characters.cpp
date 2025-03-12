Question Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

Solution:
bool isContainAllChars(vector<int>& mp)
{
    return (mp[0] > 0 && mp[1] > 0 && mp[2] > 0);
}
int numberOfSubstrings(string s)
{
    int n = s.length();
    int ans = 0, i = 0, j = 0;
    vector<int> freq(3, 0);

    while(j < n)
    {
        freq[s[j]-'a']++;

        while(isContainAllChars(freq))
        {
            ans += (n - j);
            freq[s[i]-'a']--;
            i++;
        }

        j++;
    }

    return ans;
}
