Question Link: https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1#

Solution:

int MissingNumber(vector<int>& array, int n) {
    // Your code goes here
    // The sum of n natural numbers is n*(n+1)/2. Using this fact from maths, we can solve this.
    int array_sum = 0;
    for(int i=0;i<(n-1);i++)
    {
        array_sum = array_sum + array[i];
    }
    return ((n*(n+1)/2) - array_sum);
}
