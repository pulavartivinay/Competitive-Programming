Question Link: https://practice.geeksforgeeks.org/problems/swap-all-odd-and-even-bits-1587115621/1#

Solution:

unsigned int swapBits(unsigned int n)
{
  // Your code here
  vector<int> even,odd;
  for(int i=0;i<32;i++)
  {
      if(n & (1 << i))
      {
          if(i%2 == 0) even.push_back(1); 
          else odd.push_back(1);
      }
      else
      {
          if(i%2 == 0) even.push_back(0); 
          else odd.push_back(0);
      }
  }
  reverse(even.begin(), even.end());
  reverse(odd.begin(), odd.end());
  int i = 0,j = 0;
  int count = 31;
  int ans = 0;
  while(i < 16 || j < 16)
  {
      if(count%2 == 0)
      {
          if(odd[i] == 1) ans += pow(2,count);
          i++;
      }
      else
      {
          if(even[j] == 1) ans += pow(2,count);
          j++;
      }
     // cout << count << " " << ans << endl;
      count--;
  }
  return ans;
}
