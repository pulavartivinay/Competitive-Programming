Question Link: https://www.codingninjas.com/codestudio/problems/873366?leftPanelTab=0

Solution:
#include <bits/stdc++.h> 
#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here
	pair<int,int> ans;
	long long int sum_arr = 0, sum = 0;
	long long int sum_arr2 = 0, sum2 = 0;
	for(int i=1;i<=n;i++)
	{
		sum_arr += arr[i-1];
		sum += i;

		sum_arr2 += pow(arr[i-1],2);
		sum2 += pow(i,2);
	}



	long long int a_b = 0;
	//A - B
	a_b = (sum - sum_arr);

	long long int diff2 = 0;
	//A2 - B2
	diff2 = (sum2 - sum_arr2);

	long long int apb = (diff2/a_b);

	int A = ((long long int)(a_b + apb)/2);
	int B = ((long long int)(apb - a_b)/2);

	ans.first = A;
	ans.second = B;
	return ans;
}
