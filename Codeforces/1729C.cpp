#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

int letterToNum(char& c)
{
    int aa = (int)(c - 96);
    return aa;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int size = s.size();

        vector<vector<int>> adj(size, vector<int>());
        for (int i = 0; i < size; ++i)
        {
            int x = letterToNum(s[i]);
            for (int j = 0; j < size; ++j)
            {
                int y = letterToNum(s[j]);
                if (i == j || y > x) continue;
                adj[i].push_back(j);
            }
        }

        vector<tuple<int, int, vector<int>>> paths;
        function<void(int, vector<vector<int>>&, vector<int>)> DFS = [&](int idx, vector<vector<int>>& adj, vector<int> cons)
        {
            if (idx == adj.size() - 1)
            {
                paths.push_back(make_tuple(-1, -1, cons));
                return;
            }
            for (const int val : adj[idx])
            {
                cons.push_back(val + 1);
                DFS(val, adj, cons);
                cons.pop_back();
            }
        };

        DFS(0, adj, {1});
        ;
        // treatment
        for (tuple<int, int , vector<int>>& el : paths)
        {
            int prev = letterToNum(s[get<2>(el)[0] - 1]);
            int tot = 0;
            for (int i = 1; i < get<2>(el).size(); ++i)
            {
                tot += abs(prev - letterToNum(s[get<2>(el)[i] - 1]));
                prev = letterToNum(s[get<2>(el)[i] - 1]);
            }
            get<0>(el) = get<2>(el).size();
            get<1>(el) = tot;
        }
        
        auto f = [&](tuple<int, int, vector<int>>& x, tuple<int, int, vector<int>>& y){ return get<0>(x) > get<0>(y); };
        sort(paths.begin(), paths.end(), f);
        
        int i = 1;
        while (i < paths.size())
        {
            if (get<0>(paths[i]) != get<0>(paths[i - 1])) break;
            ++i;
        }
        paths.erase(paths.begin() + i, paths.end());
        

        auto f2 = [&](tuple<int, int, vector<int>>& x, tuple<int, int, vector<int>>& y){ return get<1>(x) < get<1>(y); };
        sort(paths.begin(), paths.end(), f2);
        
        i = 1;
        while (i < paths.size() - 1)
        {
            if (get<1>(paths[i]) != get<1>(paths[i - 1])) break;
            ++i;
        }
        paths.erase(paths.begin() + i, paths.end());

        for (const tuple<int, int, vector<int>>& v : paths)
        {
            cout << get<1>(v) << " " << get<0>(v) << endl;   
            for (const int x : get<2>(v)) cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}
