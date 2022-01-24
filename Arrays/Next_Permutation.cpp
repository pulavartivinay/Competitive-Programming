Question Link: https://practice.geeksforgeeks.org/problems/next-permutation5226/1

Solution:

vector<int> nextPermutation(int N, vector<int> arr)
{
    // code here
    int k = -1;
    for(int i=0;i<N-1;i++)
    {
        if(arr[i] < arr[i+1]) k = i;
    }
    if(k == -1)
    {
        sort(arr.begin(), arr.end());
        return arr;
    }
    int l = -1;
    for(int i=k+1;i<N;i++)
    {
        if(arr[k] < arr[i]) l = i;
    }
    swap(arr[k], arr[l]);
    reverse(arr.begin()+k+1, arr.end());
    return arr;
}
