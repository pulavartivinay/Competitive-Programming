Question Link: https://leetcode.com/problems/powx-n/description/

Solution:
double myPow(double x, int n) {
    if(n == 0) return 1;

    long long int nn = abs(n);
    double ans = 1, base = x;
    while(nn > 0)
    {
        if(nn&1 == 1) ans *= base;

        base = base*base;
        nn = (nn >> 1);
    }
    if(n < 0) return (double)((double)1/(double)ans);
    else return ans;
}
