Question Link: https://leetcode.com/problems/reverse-vowels-of-a-string/description/

Solution:
bool isVowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;

    return false;
}
string reverseVowels(string s) {
    int n = s.length();
    int i = 0, j = n-1;

    while(i < j)
    {
        while(i < j && !isVowel(s[i])) i++;
        while(i < j && !isVowel(s[j])) j--;

        if(i >= j) break;
        swap(s[i], s[j]);
        i++;
        j--;
    }

    return s;
}
