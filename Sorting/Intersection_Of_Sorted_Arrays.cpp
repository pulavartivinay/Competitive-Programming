// Find the intersection of two sorted arrays.
// OR in other words,
// Given 2 sorted arrays, find all the elements which occur in both the arrays.
// Example :
// Input : 
//     A : [1 2 3 3 4 5 6]
//     B : [3 3 5]
// Output : [3 3 5]
// Input : 
//     A : [1 2 3 3 4 5 6]
//     B : [3 5]
// Output : [3 5]

Solution:
  vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> c;
    int m = A.size();// given A and B are two sorted arrays.
    int n = B.size();
    int i = 0;
    int j = 0;
    while(i < m and j < n)
    {
        if(A[i] == B[j])
        {
            c.push_back(A[i]);
            i = i + 1;
            j = j + 1;
        }
        else if(A[i] > B[j])
        {
            j = j + 1;
        }
        else if(A[i] < B[j])
        {
            i = i + 1;
        }
    }
    return c;
}
