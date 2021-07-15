Question Link: https://practice.geeksforgeeks.org/problems/sum-of-two-numbers-without-using-arithmetic-operators/1/#

Solution:

int sum(int a , int b)
{
    //code here
    int ans = 0;
    int carry = 0;
    for(int i=0;i<32;i++)
    {
        int h = (1 << i);
        if(carry)
        {
            if(a&h && b&h) ans += pow(2,i);
            else if(!(a&h) && !(b&h))
            {
                carry = 0;
                ans += pow(2,i);
            }
        }
        else
        {
            if(a&h && b&h)
            {
                carry = 1;
            }
            else if(a&h || b&h) ans += pow(2,i);
        }
    }
    return ans;
}
