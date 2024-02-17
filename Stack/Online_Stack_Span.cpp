Question Link: https://leetcode.com/problems/online-stock-span/description/

Solution:
class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
    }
    
    int next(int price) {
        int cnt = 1;
        while(!st.empty() && price >= st.top().first)
        {
            cnt += st.top().second;
            st.pop();
        }

        st.push({price, cnt});
        return cnt;
    }
};
