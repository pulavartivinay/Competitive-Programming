// Given a string A representing a roman numeral.
// Convert A into integer.
// A is guaranteed to be within the range from 1 to 3999.
// NOTE: Read more
// details about roman numerals at Roman Numeric System
// Input Format
// The only argument given is string A.
// Output Format
// Return an integer which is the integer verison of roman numeral string.
// For Example
// Input 1:
//     A = "XIV"
// Output 1:
//     14
// Input 2:
//     A = "XX"
// Output 2:
//     20
    
Solution:
  int Solution::romanToInt(string A) {
    int li = 0;
    int i = 0;
    map<char,int> roman_map;
    roman_map['I'] =   1;
	roman_map['V'] =   5;
	roman_map['X'] =  10;
	roman_map['L'] =  50;
	roman_map['C'] = 100;
	roman_map['D'] = 500;
	roman_map['M'] =1000;
    while(i < A.size())
    {
        if(i+1 < A.size() and roman_map[A[i]] < roman_map[A[i+1]])
        {
            li = li + (roman_map[A[i+1]] - roman_map[A[i]]);
            i = i + 2;
        }
        else
        {
            li = li + roman_map[A[i]];
            i = i + 1;
        }
    }
    return li;
}
