// Given the array of strings A,
// you need to find the longest string S which is the prefix of ALL the strings in the array.
// Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1
// and S2.
// For Example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".
// Input Format
// The only argument given is an array of strings A.
// Output Format
// Return longest common prefix of all strings in A.
// For Example
// Input 1:
//     A = ["abcdefgh", "aefghijk", "abcefgh"]
// Output 1:
//     "a"
//     Explanation 1:
//         Longest common prefix of all the strings is "a".
// Input 2:
//     A = ["abab", "ab", "abcd"];
// Output 2:
//     "ab"
//     Explanation 2:
//         Longest common prefix of all the strings is "ab".
        
Solution:
  string commonPrefixUtil(string str1, string str2) 
  { 
      string result; 
      int n1 = str1.length(), n2 = str2.length(); 
  
      // Compare str1 and str2 
      for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++) 
      { 
          if (str1[i] != str2[j]) 
              break; 
          result.push_back(str1[i]); 
      } 
  
     return (result); 
  } 
  string Solution::longestCommonPrefix(vector<string> &A) {
      string li = A[0];
      for(int i=1;i<A.size();i++)
      {
          li = commonPrefixUtil(li,A[i]);
      }
      return li;
  }
