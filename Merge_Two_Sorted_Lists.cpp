// Given two sorted integer arrays A and B, merge B into A as one sorted array.
//  Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
// TIP: C users, please malloc the result into a new array and return the result. 
// If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n
// Example :
// Input : 
//          A : [1 5 8]
//          B : [6 9]
// Modified A : [1 5 6 8 9]

Solution:
  void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> c;
    int m = A.size();
    int n = B.size();
    int i = 0;
    int j = 0;
    while(i < m and j < n)
    {
        if(A[i] < B[j])
        {
            c.push_back(A[i]);
            i = i + 1;
        }
        else
        {
            c.push_back(B[j]);
            j = j + 1;
        }
    }
    while(i < m)
    {
        c.push_back(A[i]);
        i = i + 1;
    }
    while(j < n)
    {
        c.push_back(B[j]);
        j = j + 1;
    }
    A = c;
}
