Question Link: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/

Solution:
bool checkPowersOfThree(int n) {
    while(n > 0)
    {
        if(n%3 == 2) return false;
        n = (n/3);
    }

    return true;
}
