Question Link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

Solution:

static bool com(Job j1, Job j2)
{
    return (j1.profit > j2.profit);
}
vector<int> JobScheduling(Job arr[], int n) 
{ 
    // your code here
    vector<int> ans;
    vector<bool> slots(n+1,0);
    sort(arr, arr+n, com);
    int profit = 0;
    int count = 0;
    for(int i=0;i<n;i++)
    {
        int h = min(n,arr[i].dead);
        if(slots[h] == 0)
        {
            slots[h] = 1;
            profit += arr[i].profit;
            count++;
        }
        else
        {
            while(h > 0 && slots[h] == 1)
            {
                h--;
            }
            if(h != 0)
            {
                slots[h] = 1;
                profit += arr[i].profit;
                count++;
            }
        }
    }
    ans.push_back(count);
    ans.push_back(profit);
    return ans;
}
