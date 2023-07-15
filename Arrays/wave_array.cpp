Question Link: https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1

Solution:

void convertToWave(vector<int>& arr, int n){
    // Your code here
    int i=0;
    while(i+2 <= n)
    {
        swap(arr[i], arr[i+1]);
        i = i + 2;
    }
    if(n&1 && arr[n-2] > arr[n-1]) swap(arr[n-2], arr[n-1]);
}
