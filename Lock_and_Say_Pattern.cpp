Question Link: https://practice.geeksforgeeks.org/problems/decode-the-pattern1138/1

Solution:

string lookandsay(int n) {
        // code here
    if(n == 1) return "1";
    else if(n == 2) return "11";
    else
    {
        string ans = "11";
        for(int i=3;i<=n;i++)
        {
            int count = 1;
            string temp = "";
            for(int j=1;j<(ans.length());j++)
            {
                if(ans[j-1] == ans[j])
                {
                    count++;
                }
                else
                {
                    temp += to_string(count);
                    temp += ans[j-1];
                    count = 1;
                }
            }
            temp += to_string(count);
            temp += ans[ans.length()-1];
            count = 1;
            ans = temp;
        }
        return ans;
    }
}
