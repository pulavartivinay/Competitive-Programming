Question Link: https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1

Solution Link: 

int NumberofElementsInIntersection (int a[], int b[], int n, int m )
    {
        // Your code goes here
        map<int,int> A;
        for(int i=0;i<n;i++)
        {
            A[a[i]]++;
        }
        int count = 0;
        for(int i=0;i<m;i++)
        {
            if(A[b[i]])
            {
                count++;
                A[b[i]] = 0;
            }
        }
        return count;
    }
