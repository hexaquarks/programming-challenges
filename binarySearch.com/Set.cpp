#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/* personal Implememtation - Faster than 67% of submissions */
class CustomSet 
{
public:
    vector<int> vals;
    unordered_map<int, int> m_map;

    CustomSet() 
    {
    }

    void add(int val) 
    {
        if (m_map.find(val) != m_map.end()) return;

        vals.push_back(val);
        m_map[val] = vals.size() - 1;
    }

    bool exists(int val) 
    {
        return m_map.find(val) != m_map.end();
    }

    void remove(int val) 
    {
        if (m_map.find(val) == m_map.end()) return;

        int last = vals.back(); 
        vals[m_map[val]] = vals.back();
				               
        vals.pop_back();	   
        m_map[last]=m_map[val];
        m_map.erase(val);
    }
};

/* Better solution */
class CustomSet {
    vector<int> root;

    public:
    CustomSet() {
    }

    void add(int val) {
        if (binary_search(root.begin(), root.end(), val)) return;
        auto itr = lower_bound(root.begin(), root.end(), val);
        root.insert(itr, val);
    }

    bool exists(int val) {
        return binary_search(root.begin(), root.end(), val);
    }

    void remove(int val) {
        if (!binary_search(root.begin(), root.end(), val)) return;
        auto itr = lower_bound(root.begin(), root.end(), val);
        root.erase(itr);
    }
};
/* Note - This makes sense since std::set<T> is in fact 
 * implemented using binary search   