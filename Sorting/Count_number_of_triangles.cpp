Question Link: https://practice.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1

Solution Link:

int findNumberOfTriangles(int arr[], int n)
    {
        // code here
        int ans = 0;
        sort(arr, arr+n);
        for(int i=0;i<(n-1);i++)
        {
            for(int j=i+1;j<n;j++)
            {
                //condition for triangle: sum of any two sides is greater than the other side.
                int k = lower_bound(arr+j+1, arr+n, arr[i] + arr[j]) - arr;
                ans = ans + (k - j - 1);
            }
        }
        return ans;
    }
