Question Link: https://practice.geeksforgeeks.org/problems/find-first-and-last-occurrence-of-x0849/1

Solution:

pair<long,long> indexes(vector<long long> v, long long x)
{
    // code here
    long long int store1 = -1;
    long long int store2 = -1;
    long long int n = v.size();
    // for left most index
    long long int low = 0;
    long long int high = n-1;
    while(low <= high)
    {
        long long int mid = (low + high)/2;
        if(v[mid] == x)
        {
            store1 = mid;
            high = mid - 1;
        }
        else if(v[mid] > x)
        {
            high = mid - 1;
        }
        else if(v[mid] < x)
        {
            low = mid + 1;
        }
    }
    // for right most index
    low = 0;
    high = n-1;
    while(low <= high)
    {
        long long int mid = (low + high)/2;
        if(v[mid] == x)
        {
            store2 = mid;
            low = mid + 1;
        }
        else if(v[mid] > x)
        {
            high = mid - 1;
        }
        else if(v[mid] < x)
        {
            low = mid + 1;
        }
    }
    pair<long long int, long long int> p;
    p.first = store1;
    p.second = store2;
    return p;
}
