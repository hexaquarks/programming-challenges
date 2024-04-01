using namespace std;

class Solution {
    using TPrereqs = map<int, vector<int>>;
    using TCache = map<int, vector<int>>;
    using TCacheStack = deque<int>;
public:
    bool existsInCache(int curr, int target, const TCache& c)  {
        if (c.empty()) return false;
        if (!c.contains(curr) || c.at(curr).empty()) return false;

        for (int cachedVal : c.at(curr)) {
            if (cachedVal == target) {
                return true;
            }
        }
        return false;
    }

    bool dfs(int curr, int target, TPrereqs& m, TCache& c, TCacheStack& sc) {
        if (curr == target) return true;
        if (!m.contains(curr) || m.at(curr).empty()) return false;

        for (int child : m.at(curr)) {
            // check for cycle
            if (find(sc.begin(), sc.end(), child) != sc.end()) continue;

            // use global cache to accelerate
            if (c.contains(child)) {
                vector<int> cv = c.at(child);
                return find(cv.begin(), cv.end(), target) != cv.end();
            }
            
            sc.push_back(child);

            bool found = dfs(child, target, m, c, sc);

            int curr = sc.back();
            sc.pop_back();
            for (int val : sc) {
                c[val].push_back(curr);
            }

            if (found) return true;
        }
        return false;
        // every dfs stack should have its own cacheStac
    }
    
    vector<bool> checkIfPrerequisite(
        int numCourses, 
        vector<vector<int>>& prerequisites, 
        vector<vector<int>>& queries) {
        
        set<int> v;
        TPrereqs m; 
        TCache c;
        deque<int> sc;
        vector<bool> ans;
        
        for (vector<int> v : prerequisites) {
            m[v[0]].push_back(v[1]);
        }

        if (m.empty()) {
            return vector<bool>(queries.size(), false);
        }

        for (vector<int> v : queries) {
            int v1 = v[0];
            int v2 = v[1];

            if (existsInCache(v1, v2, c)) {
                ans.push_back(true);    
            } else {
                sc.push_back(v1);
                ans.push_back(dfs(v1, v2, m, c, sc));
                sc.pop_back();
            }
        }

        return ans;
    }
};