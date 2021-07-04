Question Link: https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1

Solution:

int circularSubarraySum(int arr[], int num){
    // your code here
    int curr_sum = arr[0];
    int glob_sum = arr[0];
    int total_sum = arr[0];
    arr[0] = -arr[0];
    for(int i=1;i<num;i++)
    {
        total_sum += arr[i];
        curr_sum = max(arr[i], curr_sum+arr[i]);
        if(curr_sum > glob_sum)
        {
            glob_sum = curr_sum;
        }
        arr[i] = -arr[i];
    }
    int store1 = glob_sum;
    if(store1 < 0) return store1;
    curr_sum = arr[0];
    glob_sum = arr[0];
    for(int i=1;i<num;i++)
    {
        curr_sum = max(arr[i], curr_sum+arr[i]);
        if(curr_sum > glob_sum)
        {
            glob_sum = curr_sum;
        }
    }
    return max(store1, total_sum + glob_sum);
}
