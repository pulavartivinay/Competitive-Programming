Question Link: https://leetcode.com/problems/roman-to-integer/description/

Solution:
int romanToInt(string s) {
	int n = s.length();
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i] == 'I') ans++;
		else if(s[i] == 'V' && (i-1 >= 0 && s[i-1] == 'I')) ans += 3;
		else if(s[i] == 'V') ans += 5;
		else if(s[i] == 'X' && (i-1 >= 0 && s[i-1] == 'I')) ans += 8;
		else if(s[i] == 'X') ans += 10;
		else if(s[i] == 'L' && (i-1 >= 0 && s[i-1] == 'X')) ans += 30;
		else if(s[i] == 'L') ans += 50;
		else if(s[i] == 'C' && (i-1 >= 0 && s[i-1] == 'X')) ans += 80;
		else if(s[i] == 'C') ans += 100;
		else if(s[i] == 'D' && (i-1 >= 0 && s[i-1] == 'C')) ans += 300;
		else if(s[i] == 'D') ans += 500;
		else if(s[i] == 'M' && (i-1 >= 0 && s[i-1] == 'C')) ans += 800;
		else if(s[i] == 'M') ans += 1000;
	}
	return ans;
}
