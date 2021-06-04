Question Link: https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1#

Solution Link:

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here 
        long long int left[n];
        long long int right[n];
        vector<long long int> product (n, 1);
        left[0] = 1;
        for(int i=1;i<n;i++)
        {
            left[i] = nums[i-1]*left[i-1];
        }
        right[n-1] = 1;
        for(int i=n-2;i>=0;i--)
        {
            right[i] = nums[i+1]*right[i+1];
        }
        for(int i=0;i<n;i++)
        {
            product[i] = left[i]*right[i];
        }
        return product;
    }
