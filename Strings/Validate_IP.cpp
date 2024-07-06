Question Link: https://www.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1

Solution:
int isValid(string s) {
    // code here
    int len = s.length();
    if(len < 7 || len > 15) return false;
    
    int dots = 0;
    for(int i=0;i<len;i++)
    {
        if(s[i] == '.') dots++;
        else if(0 <= s[i]-'0' && s[i]-'0' <= 9) continue;
        else return false;
    }
    
    if(dots != 3) return false;
    
    string str = "";
    for(int i=0;i<len;i++)
    {
        if(s[i] == '.')
        {
            if((str == "") || (str.length() > 1 && str[0] == '0')) return false;
            int num = stoi(str);
            if(num < 0 || num > 255) return false;
            str = "";
        }
        else str += s[i];
    }
    
    if((str == "") || (str.length() > 1 && str[0] == '0')) return false;
    int num = stoi(str);
    if(num < 0 || num > 255) return false;
    
    return true;
}
