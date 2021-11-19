Question Link: https://practice.geeksforgeeks.org/problems/geek-collects-the-balls5515/1

Solution:

int maxBalls(int N, int M, int a[], int b[])
{
    // code here
    int ans = 0;
    int aSum = 0;
    int bSum = 0;
    int i=0;
    int j=0;
    while(i<N && j<M)
    {
        if(a[i] < b[j])
        {
            aSum += a[i];
            i++;
        }
        else if(a[i] > b[j])
        {
            bSum += b[j];
            j++;
        }
        else
        {
            while(i+1 < N && a[i] == a[i+1])
            {
                aSum += a[i];
                i++;
            }
            aSum += a[i];
            while(j+1 < M && b[j] == b[j+1])
            {
                bSum += b[j];
                j++;
            }
            bSum += b[j];
            ans += max({aSum,bSum});
            aSum = 0;
            bSum = 0;
            i++;
            j++;
        }
    }
    while(i < N)
    {
        aSum += a[i];
        i++;
    }
    while(j < M)
    {
        bSum += b[j];
        j++;
    }
    ans += max({aSum,bSum});
    return ans;
}
