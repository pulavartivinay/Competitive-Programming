Question Link: https://www.codingninjas.com/studio/problems/893000?topList=striver-sde-sheet-problems&leftPanelTabValue=PROBLEM

Solution:
int minCharsforPalindrome(string str) {
	// Write your code here.
	int n = str.length();
	int max_palindrome_len = 1;

	for(int i=0;i<n;i++)
	{
		// odd palindromes
		int left = i-1, right = i+1, cnt = 1;
		while(left >= 0 && right < n && str[left] == str[right])
		{
			left--;
			right++;
			cnt += 2;
		}

		if (left == -1) max_palindrome_len = max(max_palindrome_len, cnt);

		// even palindormes
		left = i, right = i+1, cnt = 0;
		while(left >= 0 && right < n && str[left] == str[right])
		{
			left--;
			right++;
			cnt += 2;
		}

		if (left == -1) max_palindrome_len = max(max_palindrome_len, cnt);
	}

	return (n - max_palindrome_len);
}
