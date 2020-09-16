/*Find the contiguous subarray within an array, A of length N which has the largest sum.

Input Format:

The first and the only argument contains an integer array, A.
Output Format:

Return an integer representing the maximum possible sum of the contiguous subarray.
Constraints:

1 <= N <= 1e6
-1000 <= A[i] <= 1000
For example:

Input 1:
    A = [1, 2, 3, 4, -10]

Output 1:
    10

Explanation 1:
    The subarray [1, 2, 3, 4] has the maximum possible sum of 10. */
    
 Solution:
    def maxSubArray(self, A):
        temp_sum =  A[0]
        answer = A[0]
       
        for i in range(1, len(A)): 
            temp_sum = max(A[i],temp_sum + A[i])
            answer = max(answer,temp_sum)
        return answer
