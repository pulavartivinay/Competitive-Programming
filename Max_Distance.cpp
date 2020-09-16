// Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].
// Input Format
// First and only argument is an integer array A.
// Output Format
// Return an integer denoting the maximum value of j - i;
// Example Input
// Input 1:
//  A = [3, 5, 4, 2]
// Example Output
// Output 1:
//  2
// Example Explanation
// Explanation 1:
//  Maximum value occurs for pair (3, 4).
 
 Solution:
  int max(int a,int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int Solution::maximumGap(const vector<int> &A) {
    int answer = 0;
    vector<pair<int,int> > b;
    for(int i=0;i<A.size();i++)
    {
        b.push_back({A[i],i});
    }
    sort(b.begin(),b.end());
    long long int max_j = -10000;
    for(int i=A.size()-1;i>=0;i--)
    {
        max_j = max(max_j,b[i].second);
        answer = max(answer,max_j - b[i].second);
    }
    return answer;
}
