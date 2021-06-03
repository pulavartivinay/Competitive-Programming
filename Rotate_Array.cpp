Question Link: https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1

Solution Link:

class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction..
    //rotating d elements counter-clockwise is same rotating (n-d) elements clockwise direction.
    void rotateArr(int arr[], int d, int n){
        // code here
        d = (d%n);
        int reverse = (n-d);
        vector<int> v (arr, arr+n);
        for(int i=0;i<n;i++)
        {
            arr[(i+reverse)%n] = v[i];
        }
    }
};
