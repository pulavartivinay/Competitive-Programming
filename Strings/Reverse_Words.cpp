Question Link: https://leetcode.com/problems/reverse-words-in-a-string/description/

Solution:
string reverseWords(string s) {
    int n = s.length(), left = 0, right = 0, i = 0;

    reverse(s.begin(), s.end());
    while(i < n)
    {
        while(i < n && s[i] == ' ') i++;
        if(i == n) break;

        while(i < n && s[i] != ' ') s[right++] = s[i++];
        reverse(s.begin()+left, s.begin()+right);
        s[right++] = ' ';
        left = right;
    }

    s.resize(right-1);
    return s;
}
