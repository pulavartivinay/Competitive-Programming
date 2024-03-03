Question Link: https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

Solution:
static bool comp(string s1, string s2)
{
    return (s1+s2 > s2+s1);
}
string printLargest(int n, vector<string> &arr) {
    // code here
    sort(arr.begin(), arr.end(), comp);
    string ans = "";
    
    for(int i=0;i<n;i++) ans += arr[i];
    return ans;
}
