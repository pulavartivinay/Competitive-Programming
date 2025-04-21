Question Link: https://leetcode.com/problems/count-the-hidden-sequences/description/

Solution:
int numberOfArrays(vector<int>& differences, int lower, int upper) {
    long long int n = differences.size();
    long long int mi = 0, mx = 0, s = 0;
    for(int i=0;i<n;i++)
    {
        s += differences[i];
        mi = min(mi, s);
        mx = max(mx, s);
    }

    int range = (mx - mi);
    return (upper - lower - range + 1) > 0 ? (upper - lower - range + 1) : 0;
}
