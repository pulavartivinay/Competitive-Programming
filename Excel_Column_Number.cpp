Given a column title A as appears in an Excel sheet, return its corresponding column number.
Problem Constraints
1 <= |A| <= 100
Input Format
First and only argument is string A.
Output Format
Return an integer
Example : AB --> 28;

Solution:
  int Solution::titleToNumber(string A) {
    int answer = 0;
    for(int i=0;i<A.size();i++)
    {
        answer = answer + (pow(26,i)*((int)A[A.size()-1-i] - 64));
    }
    return answer;
}
