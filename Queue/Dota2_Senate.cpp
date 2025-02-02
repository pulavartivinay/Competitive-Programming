Question Link: https://leetcode.com/problems/dota2-senate/description/

Solution:
string predictPartyVictory(string senate) {
    int n = senate.length();

    queue<int> rad, dir;

    for(int i=0;i<n;i++)
    {
        if(senate[i] == 'R') rad.push(i);
        else dir.push(i);
    }

    int i = 0;
    while(!rad.empty() && !dir.empty())
    {
        int d = dir.front();
        int r = rad.front();

        if(d < r) dir.push(i+n);
        else rad.push(i+n);

        dir.pop();
        rad.pop();

        i++;
    }

    if(dir.empty()) return "Radiant";
    else return "Dire";
}
