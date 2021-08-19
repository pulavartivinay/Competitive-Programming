Question Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/

Solution:

char nextGreatestLetter(vector<char>& letters, char target) 
{
    char ans = '.';
    int n = letters.size();
    if(target >= letters[n-1]) return letters[0];
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(letters[mid] <= target) 
        {
            low++;
            ans = letters[mid];
        }
        else if(letters[mid] > target) 
        {
            high--;
            ans = letters[mid];
        }
    }
    return ans;
}
