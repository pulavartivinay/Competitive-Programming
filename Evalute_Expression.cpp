Question Link: https://www.interviewbit.com/problems/evaluate-expression/

Solution:

int Solution::evalRPN(vector<string> &A) {
    int n = A.size();
    stack<string> s;
    for(int i=0;i<n;i++)
    {
        if(A[i] == "+")
        {
            int a = stoi(s.top());
            s.pop();
            int b = stoi(s.top());
            s.pop();
            int hi = (a + b);
            s.push(to_string(hi));
        }
        else if(A[i] == "-")
        {
            int a = stoi(s.top());
            s.pop();
            int b = stoi(s.top());
            s.pop();
            s.push(to_string(b - a));
        }
        else if(A[i] == "*")
        {
            int a = stoi(s.top());
            s.pop();
            int b = stoi(s.top());
            s.pop();
            int hi = (a * b);
            s.push(to_string(hi));
        }
        else if(A[i] == "/")
        {
            int a = stoi(s.top());
            s.pop();
            int b = stoi(s.top());
            s.pop();
            int hi = (b/a);
            s.push(to_string(hi));
        }
        else
        {
            s.push(A[i]);
        }
    }
    int ans = stoi(s.top());
    return ans;
}
