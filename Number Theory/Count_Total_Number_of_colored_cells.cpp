Question Link: https://leetcode.com/problems/count-total-number-of-colored-cells/description/

Solution:
long long coloredCells(int n) {
    //ans = 1 + 3 + 5 + 7 ... (2*n -1)  + (.... 7 + 5 + 3 + 1)
    //ans + (2*n - 1) = (2*(n**2)) - (2*n) + 1
    long long int ans = 1;
    ans += 2*pow(n, 2);
    ans -= (2*n);

    return ans;
}
