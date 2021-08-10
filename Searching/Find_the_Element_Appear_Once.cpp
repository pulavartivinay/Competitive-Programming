Question Link: https://practice.geeksforgeeks.org/problems/element-appearing-once2552/1

Solution:

int search(int A[], int N){
    //code
    // 1. check if the boundary element is the the unique element.
    if(A[0] != A[1]) return A[0];
    else if(A[N-2] != A[N-1]) return A[N-1];
    else // Apply Binary Search Algorithm on the sorted array until u reach to the unique element.
    {
        int low = 0;
        int high = N-1; // before the unique element, elements are arranged in even odd indices fashion and after the unique element, elements are arranged in odd even indices fashion (if u still don't get it, take one example and their corresponding indices). 
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(A[mid] == A[mid-1] && mid&1) low = mid+1;
            else if(A[mid] == A[mid-1] && mid%2 == 0) high = mid-2;
            else if(A[mid] == A[mid+1] && mid&1) high = mid-1;
            else if(A[mid] == A[mid+1] && mid%2 == 0) low = mid+2;
            else return A[mid];
        }
    }
}
