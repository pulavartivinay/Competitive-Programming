/* Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.

Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.



Input Format:

The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
Output Format:

Return a 2-d matrix that satisfies the given conditions.
Constraints:

1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:

Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]

Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]

Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]

Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]
   */
 
Solution:
  void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    bool isCol = false;
    for (int i = 0; i < A.size(); i++) 
    {

      // Since first cell for both first row and first column is the same i.e. matrix[0][0]
      // We can use an additional variable for either the first row/column.
      // For this solution we are using an additional variable for the first column
      // and using matrix[0][0] for the first row.
      if (A[i][0] == 0) 
      {
        isCol = true;
      }

      for (int j = 1; j < A[1].size(); j++) 
      {
        // If an element is zero, we set the first element of the corresponding row and column to 0
        if (A[i][j] == 0)
        {
          A[0][j] = 0;
          A[i][0] = 0;
        }
      }
    }

    // Iterate over the array once again and using the first row and first column, update the elements.
    for (int i = 1; i < A.size(); i++) 
    {
      for (int j = 1; j < A[1].size(); j++)
      {
        if (A[i][0] == 0 || A[0][j] == 0) 
        {
          A[i][j] = 0;
        }
      }
    }

    // See if the first row needs to be set to zero as well
    if (A[0][0] == 0) 
    {
      for (int j = 0; j < A[1].size(); j++) 
      {
        A[0][j] = 0;
      }
    }

    // See if the first column needs to be set to zero as well
    if (isCol) 
    {
      for (int i = 0; i < A.size(); i++)
      {
        A[i][0] = 0;
      }
    }

}
