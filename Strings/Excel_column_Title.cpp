Question Link: https://practice.geeksforgeeks.org/problems/excel-sheet5448/1#

Solution:

string ExcelColumn(int N)
{
    // Your code goes here
    string ans = "";
    while(N != 0)
    {
        int h = (N%26);
        if(h == 0)
        {
            h = 26;
        }
        h--;
        ans += 'A' + h;
        N = N/26;
        if(N == 1 && h == 25) break;
        if(h == 25) N--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
