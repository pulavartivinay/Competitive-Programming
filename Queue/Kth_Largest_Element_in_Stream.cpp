Question Link: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1#

Solution Link:

vector<int> kthLargest(int k, int arr[], int n) {
  // code here
  vector<int> ans;
  priority_queue<int> pq;
  for(int i=0;i<n;i++)
  {
      pq.push(-1 * arr[i]);
      // size of the stream less than k, so return -1.
      if(pq.size() < k)
      {
          ans.push_back(-1);
      }
      // size of the stream gretaer than k, so make it priority queue size as "k" and return top element.
      else if(pq.size() > k)
      {
          pq.pop();
          ans.push_back(-1 * pq.top());
      }
      // size of the stream is k, so just return the top most element in the priority queue(min heap).
      else
      {
          ans.push_back(-1 * pq.top());
      }
  }
  return ans;
  }
