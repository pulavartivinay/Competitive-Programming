Question Link: https://www.codingninjas.com/codestudio/problems/873366?leftPanelTab=0

Solution:
#include <bits/stdc++.h> 
#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here
	long long int sum_arr = 0, sum = 0;
	long long int sum_arr2 = 0, sum2 = 0;
	for(int i=1;i<=n;i++)
	{
		sum_arr += arr[i-1];
		sum += i;
	
		sum_arr2 += pow(arr[i-1],2);
		sum2 += pow(i,2);
	}
	
	long long int linearEq1 = 0;
	//A - B
	linearEq1 = (sum - sum_arr);
	
	long long int linearEq2 = 0;
	//A2 - B2
	linearEq2 = (sum2 - sum_arr2);
	
	//A + B
	long long int linearEq3 = (linearEq2/linearEq1);
	
	int A = ((long long int)(linearEq1 + linearEq3)/2);
	int B = ((long long int)(linearEq3 - linearEq1)/2);
	
	return {A, B};
}
