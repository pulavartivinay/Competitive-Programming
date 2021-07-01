Question Link: https://practice.geeksforgeeks.org/problems/lru-cache/1#

Solution Link:

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    unordered_map<int,int> m;
    int n;
    vector<int> v;
    LRUCache(int cap)
    {
        // code here
        this->n = cap;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(m[key] == 0)
        {
            return -1;
        }
        else
        {
            int li = -1;
            for(int i=0;i<(v.size());i++)
            {
                if(v[i] == key)
                {
                    li = i;
                    break;
                }
            }
            v.erase(v.begin() + li);
            v.push_back(key);
            return m[key];
        }
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here 
        if(m[key] == 0)
        {
            if(v.size() < n) //page fault
            {
                v.push_back(key);
                m[key] = value;
            }
            else
            {
                m[v[0]] = 0;
                v.erase(v.begin());
                v.push_back(key);
                m[key] = value;
            }
        }
        else
        {
            int li = -1;
            for(int i=0;i<(v.size());i++)
            {
                if(v[i] == key)
                {
                    li = i;
                    break;
                }
            }
            m[v[li]] = 0;
            v.erase(v.begin() + li);
            v.push_back(key);
            m[key] = value;
        }
    }
};
