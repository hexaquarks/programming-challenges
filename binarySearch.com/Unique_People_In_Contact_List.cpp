#include <vector>
#include <unordered_set>

using namespace std;

/* My solution - Faster than 90% */
int solve(vector<vector<string>>& contacts) 
{
    int n = contacts.size();
    if (n == 0) return 0;

    unordered_set<string> mem;
    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        bool found = false;
        for (string& s : contacts[i])
        {
            if (mem.find(s) != mem.end()) found = true;
            else mem.insert(s);
        }
        if (!found) ++ans;
    }
    return ans;
<<<<<<< HEAD
}
=======
}
>>>>>>> e11b97cac4424f468d82a8e424be5a699019368f
