Question Link: https://practice.geeksforgeeks.org/problems/implement-atoi/1

Solution:

int atoi(string str)
{
    //Your code here
    int start = 0, ans = 0;
    if(str[0] == '-') start = 1;
    for(int i=start;i<str.length();i++)
    {
        if(48 <= str[i] && str[i] <= 57) ans = ans*10 + int(str[i]) - 48;
        else return -1;
    }
    if(start == 1) return -1*ans;
    return ans;
}
