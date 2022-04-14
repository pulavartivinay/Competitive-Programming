Question Link: https://practice.geeksforgeeks.org/problems/moving-on-grid1135/1#

Solution:

string movOnGrid(int r, int c) 
{
    // code here
    r = (r-1)%7;
    c = (c-1)%4;
    if(r == c) return "ARYA";
    else return "JON";
}
