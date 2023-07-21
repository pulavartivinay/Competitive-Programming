Question Link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/

Solution:
int binarysearch(vector<int>& A, int key, int start, int end)
{
    while(start <= end)
    {
        int mid = start + ((end - start)/2);
        if(A[mid] == key) return mid;
        else if(key < A[mid]) end = mid-1;
        else start = mid+1;
    }
    return -1;
}
int findpivot(vector<int>& A)
{
    int n = A.size();

    int start = 0, end = n-1;
    while(start <= end)
    {
        int mid = start + ((end - start)/2);
        if(mid < n-1 && A[mid] > A[mid+1]) return mid;
        else if(mid > 0 && A[mid-1] > A[mid]) return mid-1; 
        else if(A[start] < A[mid]) start = mid;
        else end = mid-1;
    }
    return -1;
}
int search(vector<int>& A, int key) {
    int n = A.size();

    int pivot = findpivot(A);
    int ans = binarysearch(A, key, 0, pivot);
    return (ans != -1) ? ans : binarysearch(A, key, pivot+1, n-1);
}
