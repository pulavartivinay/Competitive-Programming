Question Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/

Solution:

int peakIndexInMountainArray(vector<int>& arr)
{
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low < high)
    {
        int mid = (low+high)/2;
        if(arr[mid] < arr[mid+1]) low++;
        else if(arr[mid] > arr[mid+1]) high--;
        if(low == high) return low;
    }
    return 0;
}
