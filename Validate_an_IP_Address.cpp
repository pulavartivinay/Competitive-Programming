Question Link: https://practice.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1

Solution:

int isValid(string s) {
    // code here
    int n = s.length();
    int count = 0;
    string temp = "";
    for(int i=0;i<n;i++)
    {
        if(48 <= s[i] && s[i] <= 57) temp += s[i];
        else if(s[i] == '.')
        {
            count++;
            if(temp == "") return 0;
            else if(temp.length() > 1 && temp[0] == '0') return 0;
            else
            {
                int a = stoi(temp);
                if(a > 255) return 0;
                temp = "";
            }
        }
        else return 0;
    }
    if(temp == "") return 0;
    else if(temp.length() > 1 && temp[0] == '0') return 0;
    else
    {
        int a = stoi(temp);
        if(a > 255) return 0;
        temp = "";
    }
    if(count != 3) return 0;
    else return 1;
}
