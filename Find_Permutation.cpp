// Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.
// D means the next number is smaller, while I means the next number is greater.
// Notes :
// 1. Length of given string s will always equal to n - 1
// 2. Your solution should run in linear time and space.
// Example :
// Input 1:
// n = 3
// s = ID
// Return: [1, 3, 2].

Solution:
  vector<int> Solution::findPerm(const string A, int B) {
    vector<int> b;
    int start = 1;
    int string_length = B-1;
    for(int i=0;i<string_length;i++)
    {
        if(A[i] == 'D')
        {
            b.push_back(B);
            B = B - 1;
        }
        else if(A[i] == 'I')
        {
            b.push_back(start);
            start = start + 1;
        }
    }
    b.push_back(start);
    return b;
}
