Question Link: https://leetcode.com/problems/greatest-common-divisor-of-strings/description/

Solution:
string gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1) return "";

    int n = str1.length();
    int m = str2.length();
    int gcd = __gcd(n, m);

    return str1.substr(0, gcd);
}
