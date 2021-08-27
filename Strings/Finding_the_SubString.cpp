// Implement strStr().
//  strstr - locate a substring ( needle ) in a string ( haystack ). 
// Try not to use standard library string functions for this question.
// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//  NOTE: Good clarification questions:
// What should be the return value if the needle is empty?
// What if both haystack and needle are empty?
// For the purpose of this problem, assume that the return value should be -1 in both cases. 

Solution:
  int Solution::strStr(const string A, const string B) {
    string temp_A = A;
    string temp_B = B;
    int li = temp_A.find(temp_B);
    if(li != -1)
    {
        return li;
    }
    else
    {
        return -1;
    }
}
