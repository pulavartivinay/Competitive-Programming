Question Link: https://practice.geeksforgeeks.org/problems/find-prime-numbers-in-a-range4718/1#

Solution:

bool isPrime(int num)
{
    if(num <= 1) return false;
    if(num <= 3) return true;

    for(int i=2;i<=ceil(sqrt(num));i++)
    {
        if(num%i == 0) return false;
    }
    return true;
}
vector<int> primeRange(int M, int N) {
    // code here
    vector<int> ans;
    for(int i=M;i<=N;i++)
    {
        if(isPrime(i)) ans.push_back(i);
    }
    return ans;
}
