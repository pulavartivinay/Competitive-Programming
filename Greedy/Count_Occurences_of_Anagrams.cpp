Question Link: https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

Solution:

int search(string pat, string txt) 
{
	    // code here
	    int n = txt.length();
        int k = pat.length();
        if (n < 0 || k < 0 || n < k) return 0;
 
        constexpr int CHARACTERS = 256;
        int count = 0;
        int index = 0;
        array<char, CHARACTERS> patArr;
        patArr.fill(0);
        array<char, CHARACTERS> txtArr;
        txtArr.fill(0);

        for (; index < k; index++) 
        {
            patArr[CHARACTERS - pat[index]]++;
            txtArr[CHARACTERS - txt[index]]++;
        }
        if (patArr == txtArr)
            count += 1;
            
        for (; index < n; index++) 
        {
            txtArr[CHARACTERS - txt[index]]++;
            txtArr[CHARACTERS
                    - txt[index - k]]--;
 
            if (patArr == txtArr)
                count += 1;
        }
        return count;
	}
