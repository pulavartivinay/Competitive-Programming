Question Link: https://leetcode.com/problems/string-matching-in-an-array/description/

Solution:
bool match(string pattern, string word)
{
    int n = pattern.length();
    int m = word.length();

    vector<int> lps(n, 0);
    int i=0, j=1;
    while(j < n)
    {
        if(pattern[i] == pattern[j]) i++;
        else i = 0;

        lps[j] = i;

        j++;
    }

    i=0, j=0; // i --> pattern j --> word
    while(i < n && j < m)
    {
        if(pattern[i] == word[j]) i++;
        else
        {
            if(i-1 >= 0)
            {
                i = lps[i-1];
                continue;
            }
            i = 0;
        }
        j++;
    }

    if(i == n) return true;

    return false;
}
vector<string> stringMatching(vector<string>& words) {
    int n = words.size();
    vector<string> ans;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i != j && match(words[i], words[j])) 
            {
                ans.push_back(words[i]);
                break;
            }
        }
    }

    return ans;
}
