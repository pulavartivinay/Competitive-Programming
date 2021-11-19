Question Link: https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

Solution Link:

string infixToPostfix(string s)
    {
        // Your code here
        int n = s.length();
        string ans = "";
        stack<char> li;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(')
            {
                li.push(s[i]);
            }
            else if(s[i] == ')')
            {
                while(li.top() != '(')
                {
                    ans += li.top();
                    li.pop();
                }
                li.pop();
            }
            else if(s[i] == '^')
            {
                if(li.empty())
                {
                    li.push(s[i]);
                }
                else if(li.top() == '^')
                {
                    ans += li.top();
                    li.pop();
                    li.push(s[i]);
                }
                else
                {
                    li.push(s[i]);
                }
            }
            else if(s[i] == '*' | s[i] == '/')
            {
                if(li.empty())
                {
                    li.push(s[i]);
                }
                else if(li.top() == '*' | li.top() == '/' | li.top() == '^')
                {
                    ans += li.top();
                    li.pop();
                    li.push(s[i]);
                }
                else
                {
                    li.push(s[i]);
                }
            }
            else if(s[i] == '+' | s[i] == '-')
            {
                while(1)
                {
                    if(li.empty())
                    {
                        li.push(s[i]);
                        break;
                    }
                    else if(li.top() == '+' | li.top() == '-' | li.top() == '*' | li.top() == '/' | li.top() == '^')
                    {
                        ans += li.top();
                        li.pop();
                    }
                    else
                    {
                        li.push(s[i]);
                        break;
                    }
                }
            }
            else
            {
                ans += s[i];
            }
        }
        while(!li.empty())
        {
            ans += li.top();;
            li.pop();
        }
        return ans;
    }
