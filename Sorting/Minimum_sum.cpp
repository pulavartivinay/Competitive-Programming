Question Link: https://practice.geeksforgeeks.org/problems/minimum-sum4058/1#

Solution:

string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";

    long long int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    long long int carry = 0;
    for (long long int i=0; i<n1; i++)
    {

        long long int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');

        carry = sum/10;
    }

    for (long long int i=n1; i<n2; i++)
    {
        long long int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    if (carry)
        str.push_back(carry+'0');

    reverse(str.begin(), str.end());

    return str;
}

string solve(int arr[], int n) {
    // code here
    sort(arr, arr+n);
    string a = "";
    string b = "";
    for(int i=0;i<n;i++)
    {
        string s = to_string(arr[i]);
        if(i%2 == 0) a += s;
        else b += s;
    }
    string r = findSum(a,b);
    long long int l = r.length();
    long long int ind = -1;
    for(long long int i=0;i<l;i++)
    {
        if(r[i]-'0' != 0) 
        {
            ind = i;
            break;
        }
    }
    string ans(r.begin()+ind, r.end());
    return ans;
}
