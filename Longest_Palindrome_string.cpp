// Given a string S, find the longest palindromic substring in S.
// Substring of string S:
// S[i...j] where 0 <= i <= j < len(S)
// Palindrome string:
// A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.
// Incase of conflict, return the substring which occurs first ( with the least starting index ).
// Example :
// Input : "aaaabaaa"
// Output : "aaabaaa"

Solution:
  string Solution::longestPalindrome(string A) {
    int max_length = 1;
    int start = 0;
    int left = 0;
    int right = 0;
    for(int i=0;i<A.size();i++)
    {
        //odd palindromes
        left = i-1;
        right = i+1;
        while(left >= 0 and right <= (A.size()-1))
        {
            if(A[left] == A[right])
            {
                if(right-left+1 > max_length)
                {
                    max_length = right-left+1;
                    start = left;
                }
            }
            else
            {
                break;
            }
            left = left - 1;
            right = right + 1;
        }
        //even palindromes
        left = i-1;
        right = i;
        while(left >= 0 and right <= (A.size()-1))
        {
            if(A[left] == A[right])
            {
                if(right-left+1 > max_length)
                {
                    max_length = right-left+1;
                    start = left;
                }
            }
            else
            {
                break;
            }
            left = left - 1;
            right = right + 1;
        }
    }
    string answer = "";
    for(int i=start;i<=(start + max_length-1);i++)
    {
        answer = answer + A[i];
    }
    return answer;
}
