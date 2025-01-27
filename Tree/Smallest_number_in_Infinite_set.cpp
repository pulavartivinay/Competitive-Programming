Question Link: https://leetcode.com/problems/smallest-number-in-infinite-set/description/

Solution:
class SmallestInfiniteSet {
public:
    int nums = 1000;
    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<bool> exist;
    SmallestInfiniteSet() {
        // according to the constraints, max elems in the priority queue is 1000
        for(int i=1;i<=nums;i++) 
        {
            pq.push(i);
            exist.push_back(true);
        }
        exist.push_back(true);
    }
    
    int popSmallest() {
        int ans = pq.top();
        pq.pop();
        exist[ans] = false;
        return ans;
    }
    
    void addBack(int num) {
        if(!exist[num])
        {
            pq.push(num);
            exist[num] = true;
        }
    }
};
