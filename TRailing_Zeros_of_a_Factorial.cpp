Given an integer A, return the number of trailing zeroes in A!.
Note: Your solution should be in logarithmic time complexity.
**Problem Constraints**
1 <= A <= 10000
**Input Format**
First and only argumment is integer A.
**Output Format**
Return an integer, the answer to the problem.
**Example Input**
Input 1:
 A = 4
Input 2:
 A = 5
**Example Output**
Output 1:
 0
Output 2:
 1
**Example Explanation**
Explanation 1:
 4! = 24
Explanation 2:
 5! = 120
 
 Solution:
  int Solution::trailingZeroes(int A) {
    int answer = 0;
    // we need to get the power of 10 in a number. but indeed we just need power of 5 because the power of 2 is greater than or equal to power of 5.
    // so just we need power of 5 to know the number of zeros of a given number.
    // Trailing 0s in n! = Count of 5s in prime factors of n!
    //              = floor(n/5) + floor(n/25) + floor(n/125) + ....
    while(A != 0)
    {
        answer = answer + (A/5);
        A = (A/5);
    }
    return answer;
}
