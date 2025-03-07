Question Link: https://leetcode.com/problems/closest-prime-numbers-in-range/description/

Solution:
bool isPrime(int num)
{
    if(num == 1) return false;
    for(int i=2;i<=(int)sqrt(num);i++)
    {
        if(num%i == 0) return false;
    }

    return true;
}
vector<int> closestPrimes(int left, int right) {
    vector<int> ans(2, -1);
    int curr_prime = -1;
    int minDiff = INT_MAX, diff;

    for(int i=left;i<=right;i++)
    {
        if(isPrime(i))
        {
            if(curr_prime != -1)
            {
                diff = (i - curr_prime);
                if(diff < minDiff)
                {    
                    ans[0] = curr_prime;
                    ans[1] = i;
                    minDiff = diff;
                }
            }
            curr_prime = i;
        }
    }

    return ans;
}
