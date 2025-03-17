Question Link: https://leetcode.com/problems/minimum-time-to-repair-cars/description/

Solution:
// Binary Search on Answer
bool canRepair(vector<int>& ranks, long long int time, int cars)
{
    int n = ranks.size();
    long long int cnt = 0;

    for(int i=0;i<n;i++)
    {
        cnt += (long long int)(sqrt(time/(long long int)ranks[i]));
    }

    return (cnt >= cars);
}
long repairCars(vector<int>& ranks, int cars) {
    int n = ranks.size();
    int min_rank = INT_MAX;

    for(int i=0;i<n;i++)
    {
        min_rank = min(min_rank, ranks[i]);
    }
    
    long long int low = 1, high = 1LL * min_rank * cars * cars;
    while(low <= high)
    {
        long long int mid = low + ((high - low)/2);
        if(canRepair(ranks, mid, cars)) high = mid-1;
        else low = mid + 1;
    }

    return low;
}
