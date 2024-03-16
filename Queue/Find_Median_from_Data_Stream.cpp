Question Link: https://leetcode.com/problems/find-median-from-data-stream/description/?envType=list&envId=xlemvyvd

Solution:
class MedianFinder {
public:
    priority_queue<int> pq1; // Max Heap
    priority_queue<int, vector<int>, greater<int>> pq2;  // Min Heap
    int n;
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        if(!pq1.empty() && pq1.top() > num) pq1.push(num);
        else pq2.push(num);

        while(pq2.size() > pq1.size() + 1)
        {
            pq1.push(pq2.top());
            pq2.pop();
        }

        while(pq1.size() > pq2.size() + 1)
        {
            pq2.push(pq1.top());
            pq1.pop();
        }

        n++;
    }
    
    double findMedian() {
        if(n & 1) {
            return (pq1.size() > pq2.size()) ? (pq1.top()) : (pq2.top());
        } else {
            return ((double) ( (double)( pq1.top() + pq2.top() )/ (double)2) );
        }
    }
};
