Question Link: https://practice.geeksforgeeks.org/problems/capacity-to-ship-packages-within-d-days/1

Solution:

int leastWeightCapacity(int arr[], int N, int D) 
{
    // code here
    int m = INT_MIN;
    int sum = 0;
    for(int i=0;i<N;i++)
    {
        m = max(m, arr[i]);
        sum += arr[i];
    }
    int low = m;
    int high = sum;
    int ans = 0;
    while(low <= high)
    {
        int mid = (low+high)/2;
        int days = D;
        int i = 0, temp = 0;
        while(i < N)
        {
            temp += arr[i];
            if(temp > mid)
            {
                days--;
                temp = arr[i];
            }
            i++;
        }
        if(temp >= 0) days--;
        if(days >= 0) 
        {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;

        // cout << ans << endl;
    }
    return ans;
}
