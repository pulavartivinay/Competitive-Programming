Question Link: https://leetcode.com/problems/sqrtx/description/

Solution:
int mySqrt(int x) {
    int ans = 0;
    int low = 0, high = x;
    while(low <= high)
    {
        long long int mid = (low + (high - low)/2);
        if(mid*mid == x) return mid;
        else if(mid*mid < x)
        {
            ans = mid;
            low = mid+1;
        } 
        else high = mid-1;
    }

    return ans;
}
