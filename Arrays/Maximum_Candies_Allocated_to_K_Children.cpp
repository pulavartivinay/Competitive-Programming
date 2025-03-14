Question Link: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

Solution:
// Binary Search on Answers
long long int distributeCandies(vector<int>& candies, int num)
{
    long long int ans = 0;
    int n = candies.size();

    for(int i=0;i<n;i++)
    {
        ans += (candies[i]/num);
    }

    return ans;
}
int maximumCandies(vector<int>& candies, long long k) {
    int n = candies.size();
    int max_candies = INT_MIN;
    long long int s = 0;
    for(int i=0;i<n;i++)
    {
        max_candies = max(candies[i], max_candies);
        s += candies[i];
    }
    if(k > s) return 0;

    int low = 1, high = max_candies;
    while(low <= high)
    {
        int mid = low + ((high - low)/2);
        long long int children = distributeCandies(candies, mid);
        if(children >= k) low = mid+1;
        else high = mid-1;
    }

    return high;
}
