/* Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.*/

Solution:
  /**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare (Interval i1,Interval i2)
{
    if (i1.start < i2.start)
    {
        return 1;
    }
    return 0;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int l;
    l = A.size();
    stack<Interval> s;
    sort(A.begin(),A.end(),compare);
    s.push(A[0]);
    for (int i= 1;i<l;i++)
    {
        Interval top = s.top();
        if (top.end < A[i].start) //no overlapping
            s.push(A[i]); 
        else if (top.end < A[i].end) //overlapping occurs
        { 
            top.end = A[i].end; 
            s.pop(); 
            s.push(top); 
        }
    }
    vector<Interval> v;
    while(!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    sort(v.begin(),v.end(),compare);
    return v;
}
