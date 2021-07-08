Question Link: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

Solution:

void sort012(int a[], int n)
{
    // code here
    int zeros = 0, ones = 0, twos = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i] == 0) zeros++;
        else if(a[i] == 1) ones++;
        else if(a[i] == 2) twos++;
    }
    int i=0;
    int j=0;
    while(i < zeros)
    {
        a[j] = 0;
        i++;
        j++;
    }
    i = 0;
    while(i < ones)
    {
        a[j] = 1;
        i++;
        j++;
    }
    i = 0;
    while(i < twos)
    {
        a[j] = 2;
        i++;
        j++;
    }
}
