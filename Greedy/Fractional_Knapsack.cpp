Question Link: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

Solution:
static bool comp(Item a, Item b)
{
    double x = (double) ((double) a.value/(double) a.weight);
    double y = (double) ((double) b.value/(double) b.weight);
    
    return (x > y);
}
//Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    sort(arr, arr+n, comp);
    
    double ans = (double) 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].weight <= W)
        {
            W -= arr[i].weight;
            ans += arr[i].value;
        }
        else
        {
            ans += (W * ((double) arr[i].value/(double) arr[i].weight));
            W = 0;
        }
        
        
        if(W <= 0) break;
    }
    
    return ans;
}
