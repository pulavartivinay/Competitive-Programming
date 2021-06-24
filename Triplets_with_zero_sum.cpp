Question Link: https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1/?company[]=Amazon&company[]=Amazon&problemType=functional&page=1&sortBy=submissions&query=company[]AmazonproblemTypefunctionalpage1sortBysubmissionscompany[]Amazon

Solution:

bool findTriplets(int arr[], int n)
{ 
    //Your code here
    sort(arr, arr+n);
    for(int i=0;i<(n-2);i++)
    {
        int j = i+1;
        int k = n-1;
        while(j < k)
        {
            if(arr[j] + arr[k] == (-arr[i]))
            {
                return 1;
            }
            else if(arr[j] + arr[k] > (-arr[i]))
            {
                k = k - 1;
            }
            else if(arr[j] + arr[k] < (-arr[i]))
            {
                j = j + 1;
            }
        }
    }
    return 0;
}
