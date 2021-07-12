Question Link: https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

Solution:

string reverseWords(string s) 
{ 
    // code here 
    stack<string> li;
    int n = s.length();
    string temp = "";
    for(int i=0;i<n;i++)
    {
        if(s[i] == '.')
        {
            li.push(temp);
            temp = "";
        }
        else
        {
            temp += s[i];
        }
    }
    li.push(temp);
    string ans = "";
    while(!li.empty())
    {
        ans += li.top();
        if(li.size() != 1) ans += ".";
        li.pop();
    }
    return ans;
}
