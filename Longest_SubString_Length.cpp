Question Link: https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1

Solution:

int longestUniqueSubsttr(string s){
    //code
    int n = s.length();
    int len = INT_MIN;
    vector<int> m(200, -1);
    int i = 0, j = 0; // take two pointers one is pointing to start position of substring and other is pointing to end position.
    while(i <= j && j < n)
    {
        if(m[s[j]] == -1) // if the chracter is not visited, just add into our sliding window and store the last occurence position of character.
        {
            m[s[j]] = j;
            j++;
        }
        else // if the character is visited, start position depends on the last occurence position of the same character. if it is greater than or equal to start position, then update start position ,else continue.
        {
            len = max(len, j-i);
            if(m[s[j]] >= i) 
            {
                i = m[s[j]];
                i++;
            }
            m[s[j]] = j;
            j++;
        }
    }
    len = max(len, j-i);
    return len;
}
