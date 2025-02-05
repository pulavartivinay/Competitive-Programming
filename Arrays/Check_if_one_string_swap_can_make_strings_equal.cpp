Question Link: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/

Solution:
bool areAlmostEqual(string s1, string s2) {
    int n = s1.length();

    int cnt = 0, first = -1, second = -1;
    for(int i=0;i<n;i++)
    {
        if(s1[i] != s2[i]) 
        {
            cnt++;
            if(first == -1) first = i;
            else if(second == -1) second  = i;
        }
    }

    if(cnt == 0) return true;
    else if(cnt == 2)
    {
        if(s1[first] == s2[second] && s1[second] == s2[first]) return true;
        return false;
    }
    else return false;
}
