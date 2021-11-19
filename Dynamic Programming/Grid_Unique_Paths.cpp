// A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).

// Path Sum: Example 1

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

// How many possible unique paths are there?

// Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

// Example :

// Input : A = 2, B = 2
// Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)
              
Solution:
  int Solution::uniquePaths(int A, int B) {
    //DP approach
    if(A == 1 or B == 1)
    {
        return 1; //for single row or column.
    }
    else
    {
        return (uniquePaths(A-1,B) + uniquePaths(A,B-1)); //from current position exploring both right and down directions and calculating the unique paths from there.
    }
}
