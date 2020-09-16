/* Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]
Sample Output:

1
If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1 .*/

Solution: 
  int Solution::repeatedNumber(const vector<int> &A) {
    vector<int> b;
    for(int i=0;i<A.size();i++)
    {
        b.push_back(A[i]);
    }
    sort(b.begin(),b.end());
    for(int i=0;i<(b.size()-1);i++)
    {
        if(b[i] == b[i+1])
        {
            return b[i];
        }
    }
    return -1;
}
