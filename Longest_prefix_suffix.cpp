Question Link: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

Solution Link:

int lps(string s)
	{
	    // Your code goes here
      //KMP ALGORITHM
	    int n = s.length();
	    int ans = 0;
	    int arr[n];
	    arr[0] = 0;
	    int i = 1;
	    while(i < n)
	    {
	        if(s[i] == s[ans])
	        {
	            ans = ans + 1;
	            arr[i] = ans;
	            i = i + 1;
	        }
	        else
	        {
	            if(ans != 0)
	            {
	                ans = arr[ans - 1];
	            }
	            else
	            {
	                arr[i] = 0;
	                i = i + 1;
	            }
	        }
	    }
	    return ans;
	}
