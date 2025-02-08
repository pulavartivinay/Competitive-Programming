Question Link: https://leetcode.com/problems/design-a-number-container-system/description/

Solution:
class NumberContainers {
public:
    // index --> number
    unordered_map<int, int> container;
    // number --> ordered set in ASC (red black tree impl)
    unordered_map<int, set<int> > mp;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        int num;
        // delete op
        if(container[index] != 0)
        {
            num = container[index];
            mp[num].erase(index);
        }

        // add op
        container[index] = number;
        mp[number].insert(index);
    }
    
    int find(int number) {
        if(mp[number].empty()) return -1;
        return *mp[number].begin();
    }
};
