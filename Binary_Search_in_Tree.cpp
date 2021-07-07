Question Link: https://practice.geeksforgeeks.org/problems/ffd66b6a0bf7cefb9987fa455974b6ea5695709e/1

Solution:

int find_height(int tree[], int n, int k)
{
    // code here
    int height = -1;
    int low = 0;
    int high = -1;
    for(int i=0;i<n;i++)
    {
        high = max(high, tree[i]);
    }
    while(low <= high)
    {
        int mid = (low+high)/2;
        int li = 0;
        for(int i=0;i<n;i++)
        {
            if(tree[i] > mid) li += tree[i]-mid; 
        }
        if(k == li)
        {
            height = mid;
            break;
        }
        else if(k < li)
        {
            low = mid + 1;
        }
        else if(k > li)
        {
            high = mid - 1;
        }
    }
    return height;
}
