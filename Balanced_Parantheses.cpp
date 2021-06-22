Question Link: https://www.interviewbit.com/problems/balanced-parantheses/

Solution:

int Solution::solve(string A) {
  int n = A.length();
  stack<char> s;
  for(int i=0;i<n;i++)
  {
      if(A[i] == '(')
      {
          s.push(A[i]);
      }
      else if(A[i] == ')')
      {
          if(!s.empty() && s.top() == '(')
          {
              s.pop();
          }
          else
          {
              return 0;
          }
      }
  }
  if(!s.empty())
  {
      return 0;
  }
  else
  {
      return 1;
  }
}
