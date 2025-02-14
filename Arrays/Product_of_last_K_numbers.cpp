Question Link: https://leetcode.com/problems/product-of-the-last-k-numbers/description/

Solution:
class ProductOfNumbers {
public:
    vector<int> pre = {1};
    int cnt;
    ProductOfNumbers() {
        cnt = 1;
    }
    
    void add(int num) {
        if(num == 0)
        {
            pre = {1};
            cnt = 1;
        }
        else
        {
            pre.push_back(pre[cnt-1] * num);
            cnt++;
        }
    }
    
    int getProduct(int k) {
        if(cnt <= k) return 0;
        return (pre[cnt-1] / pre[cnt - k -1]);
    }
};
