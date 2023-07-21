Question Link: https://www.codingninjas.com/studio/problems/1062679?topList=striver-sde-sheet-problems&leftPanelTab=0

Solution:
int NthRoot(int n, int m) {
  // Write your code here.
  //k**n = m;
  int start = 1, end = m;
  while(start <= end)
  {
    int mid = (start + (end - start)/2);
    if(pow(mid, n) == m) return mid;
    else if(pow(mid, n) < m) start = mid+1;
    else end = mid-1;
  }
  return -1;
}
