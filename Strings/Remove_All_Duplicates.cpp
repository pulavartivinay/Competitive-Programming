Question Link: https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1

Solution:
string removeDuplicates(string str) {
    // code here
    string ans = "";
    int n = str.length();
    unordered_map<char, int> mp;
    for(int i=0;i<n;i++)
    {
        mp[str[i]]++;
        if(mp[str[i]] == 1) ans += str[i];
    }
    return ans;
}
