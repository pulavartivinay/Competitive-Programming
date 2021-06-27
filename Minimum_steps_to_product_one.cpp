Question Link: https://practice.geeksforgeeks.org/problems/minimum-steps-to-make-product-equal-to-one/1/

Solution:

int makeProductOne(int arr[], int N) {
    // code here
    int neg = 0;
    int pos = 0;
    int zeros = 0;
    int count = 0;
    // logic: update all positive including zero to 1 and all negatives to -1.
    // if there are odd negatives, then check for zeros(if exists, no change in answer) and postive(just add two steps to answer).
    for(int i=0;i<N;i++)
    {
        if(arr[i] == 0)
        {
            zeros = zeros + 1;
            count = count + 1;
        }
        else if(arr[i]> 0)
        {
            pos = pos + 1;
            count = count + (arr[i] - 1);
        }
        else
        {
            neg = neg + 1;
            count = count + (-1 - arr[i]);
        }
    }
    if(neg&1) // odd negatives
    {
        if(zeros > 0)
        {
            return count;
        }
        else
        {
            count = count + 2;
        }
    }
    return count;
}
