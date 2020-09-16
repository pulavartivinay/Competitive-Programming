// Given numRows, generate the first numRows of Pascal’s triangle.

// Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

// Example:

// Given numRows = 5,

// Return

// [
//      [1],
//      [1,1],
//      [1,2,1],
//      [1,3,3,1],
//      [1,4,6,4,1]
// ]

Solution:
  vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> > b;
    for(int i=1;i<=A;i++)
    {
        if(i == 1)
        {
            vector<int> temp1;
            temp1.push_back(1);
            b.push_back(temp1);
            temp1.clear();
        }
        else if(i == 2)
        {
            vector<int> temp2;
            temp2.push_back(1);
            temp2.push_back(1);
            b.push_back(temp2);
            temp2.clear();
        }
        else
        {
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<=i-2;j++)
            {
                int a = b[i-2][j] + b[i-2][j-1];
                temp.push_back(a);
            }
            temp.push_back(1);
            b.push_back(temp);
            temp.clear();
        }
    }
    return b;
}
