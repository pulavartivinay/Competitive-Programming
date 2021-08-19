Question Link: https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1

Solution:

int majorityElement(int arr[], int size)
{
    // your code here
    unordered_map<int,int> m;
    for(int i=0;i<size;i++)
    {
        m[arr[i]] = m[arr[i]] + 1;
        if(m[arr[i]] > (size/2))
        {
            return arr[i];
        }
    }
    return -1;
}
