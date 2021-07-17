Question Link: https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

Solution:

bool ispar(string x)
{
    // Your code here
    stack<char> s;
    int n = x.length();
    for(int i=0;i<n;i++)
    {
        if(x[i] == '{' || x[i] == '(' || x[i] == '[')
        {
            s.push(x[i]);
        }
        else if(x[i] == '}')
        {
            if(!s.empty() && s.top() == '{') s.pop();
            else return 0;
        }
        else if(x[i] == ')')
        {
            if(!s.empty() && s.top() == '(') s.pop();
            else return 0;
        }
        else if(x[i] == ']')
        {
            if(!s.empty() && s.top() == '[') s.pop();
            else return 0;
        }
    }
    if(s.empty()) return 1;
    else return 0;
}
