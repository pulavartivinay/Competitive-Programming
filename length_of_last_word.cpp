Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.
Example:
Given s = "Hello World",
return 5 as length("World") = 5.
Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.

Solution:
  int Solution::lengthOfLastWord(const string A) {
    string temp = A;
    int count = 0;
    int j = A.size()-1;
    while(A[j] == ' ')
    {
        j--;
    }
    for(int i=j;i>=0;i--)
    {
        if(A[i] == ' ')
        {
            break;
        }
        else
        {
            count = count + 1;
        }
    }
    return count;
}
