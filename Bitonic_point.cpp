Question Link: https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1


Solution Link:
	int findMaximum(int arr[], int n) {
	    // code here
	    sort(arr, arr+n);
	    return arr[n-1];
	}
