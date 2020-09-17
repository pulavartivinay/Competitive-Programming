// Given a positive integer A, return its corresponding column title as appear in an Excel sheet.
// Problem Constraints
// 1 <= A <= 1000000000
// Input Format:
// First and only argument is integer A.
// Output Format:
// Return a string, the answer to the problem.
// Example : 26 --> Z; 30 --> AD;

Solution:
  string Solution::convertToTitle(int A) {
    string s;
    while(A != 0)
    {
        int temp = int(A%26);
        if(temp == 0)//handling when A is 26(alphabet is 'Z')
        {
            temp = 26;
            
        }
        A = int(A/26);
        s = s + (char)(temp+64);//hint: finding remainder,adding 64,converting to corresponding ASCII character and appending it to the string.
        if(A == 1 and temp == 26)//handling when A is 26(alphabet is 'Z')
        {
            break;
        }
        if(temp == 26)//handling when A is 26(alphabet is 'Z')
        {
            A = A - 1;
        }
    }
    reverse(s.begin(),s.end());//reversing the string
    return s;
}

