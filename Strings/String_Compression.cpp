Question Link: https://leetcode.com/problems/string-compression/description/

Solution:
int compress(vector<char>& chars) {
    int n = chars.size(), input_ptr = 0;
    char curr_chr = chars[0];
    string len_str = "1";

    for(int i=1;i<n;i++)
    {
        if(chars[i] == curr_chr) 
        {
            int a = stoi(len_str);
            a++;
            len_str = to_string(a);
        }
        else
        {
            chars[input_ptr++] = curr_chr;
            if(len_str != "1")
            {
                int len = len_str.length();
                int j = 0;
                while(j < len) chars[input_ptr++] = len_str[j++];
            }
            len_str = "1";
            curr_chr = chars[i];
        }
    }

    chars[input_ptr++] = curr_chr;
    if(len_str != "1")
    {
        int len = len_str.length();
        int j = 0;
        while(j < len) chars[input_ptr++] = len_str[j++];
    }

    return input_ptr;
}
