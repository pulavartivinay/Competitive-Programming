Question Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/

Solution:
int numOfSubarrays(vector<int>& arr) {
    long long int mod = pow(10,9)+7;
    int n = arr.size();
    long long int sum = 0, ans = 0, even_cnt = 0, odd_cnt = 0;
    
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        if(sum & 1)
        {
            ans += even_cnt;
            odd_cnt++;
            ans++;
        }
        else
        {
            ans += odd_cnt;
            even_cnt++;
        }
    }

    return (ans%mod);
}
