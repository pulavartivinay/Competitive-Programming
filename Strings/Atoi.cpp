// Implement atoi to convert a string to an integer.
// Example :
// Input : "9 2704"
// Output : 9
// Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.
//  Questions: Q1. Does string contain whitespace characters before the number?
// A. Yes Q2. Can the string have garbage characters after the number?
// A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
// A. Return 0. Q4. What if the integer overflows?
// A. Return INT_MAX if the number is positive, INT_MIN otherwise. 
// Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.

Solution:
  int Solution::atoi(const string str) {
    int sign = 1, base = 0, i = 0; 
    while (str[i] == ' ')
    { 
        i++; 
    }
    if (str[i] == '-' || str[i] == '+') { 
        sign = 1 - 2 * (str[i++] == '-'); 
    } 
    // checking for valid input 
    while (str[i] >= '0' && str[i] <= '9') { 
        // handling overflow test case 
        if (base > INT_MAX / 10 
            || (base == INT_MAX / 10 
                && str[i] - '0' > 7)) { 
            if (sign == 1) 
                return INT_MAX; 
            else
                return INT_MIN; 
        } 
        base = 10 * base + (str[i++] - '0'); 
    } 
    return base * sign;
}
