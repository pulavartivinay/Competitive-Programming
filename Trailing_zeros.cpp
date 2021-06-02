Question Link : https://practice.geeksforgeeks.org/problems/trailing-zeroes-in-factorial5134/1

Solution Link:

class Solution
{
public:
    int trailingZeroes(int N)
    {
        // Write Your Code here
        int a = 1;
        int count = 0;
        while(1)
        {
            if(N/pow(5,a) == 0)
            {
                break;
            }
            else
            {
                count = count + (N/pow(5,a));
                a = a + 1;
            }
        }
        return count;
    }
};
