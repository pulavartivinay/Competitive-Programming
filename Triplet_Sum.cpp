Question Link: https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

Solution Link:

bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A, A+n);
        int ans = 0;
        for(int i=0;i<(n-2);i++)
        {
            int low = (i+1);
            int high = (n-1);
            while(low < high)
            {
                if(A[low] + A[high] == (X - A[i]))
                {
                    ans = 1;
                    break;
                }
                else if(A[low] + A[high] < (X - A[i]))
                {
                    low = low + 1;
                }
                else if(A[low] + A[high] > (X - A[i]))
                {
                    high = high - 1;
                }
            }
            if(ans)
            {
                break;
            }
        }
        return ans;
    }
