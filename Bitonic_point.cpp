Question Link: https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1


Solution:

int findMaximum(int arr[], int n) {
    // code here
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
	if(low == high)
	{
	    return arr[low];
	}
	int mid = (low+high)/2;
	if(arr[mid] < arr[mid+1])
	{
	    low = mid + 1;
	}
	else if(arr[mid] > arr[mid+1])
	{
	    high = mid;
	}
    }
}

