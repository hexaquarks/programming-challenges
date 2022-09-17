#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

unordered_map<string, int> mem;

int solve(string& s)
{
    if (mem.count(s)) return mem[s]; // memoization
    int count = 0;
    for (const char& c : s) if (c == 'o') ++count;
    int size = s.size();
    for (int i = 0; i < size; ++i) 
    { 
        if (s[i] == 'o') 
        {
            if (i + 2 < size && s[i + 1] == 'o' && s[i + 2] == '-') 
            {
                s[i] = s[i + 1] = '-';
                s[i + 2] = 'o';
                count = min(count, solve(s));
                s[i] = s[i + 1] = 'o';
                s[i + 2] = '-';
            }
            if (i - 2 >= 0 && s[i - 1] == 'o' && s[i - 2] == '-') 
            {
                s[i] = s[i - 1] = '-';
                s[i - 2] = 'o';
                count = min(count, solve(s));
                s[i] = s[i - 1] = 'o';
                s[i - 2] = '-';
            }
        }
    }
    mem[s] = count;
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    
    int n;
    cin >> n;
    
    cin.ignore();
    
    while (n--)
    {
        string s;
        getline(cin, s);
        
        cout << solve(s) << endl;
    }
    return 0;
}


/* DFS alternative */

// #include <bits/stdc++.h>
// using namespace std;

// #pragma GCC optimize("O3")
// #pragma GCC target("sse4")


// vector<pair<int, int>> getRoots(vector<bool>& v)
// {
//     if (v.size() < 3) return {};
//     vector<pair<int, int>> roots{};
//     for (int i = 0; i < v.size() - 2; ++i)
//     {
//         // two cases
//         if (!v[i] && v[i+1] && v[i+2])
//         {
//             roots.push_back(make_pair(i+1, 0));
//         }
//         else if (v[i] && v[i+1] && !v[i+2])
//         {
//             roots.push_back(make_pair(i+1, 1));
//         }
//     }
//     return roots;
// }

// int getPeebles(vector<bool>& v)
// {
//     auto tot = count(v.begin(), v.end(), true);
//     return tot;
// }

// void dfs(vector<bool>& v, vector<pair<int, int>>& roots, unordered_set<vector<bool>>& visited, int& minVal)
// {
//     if (roots.size() == 0)
//     {
//         if (getPeebles(v) < minVal) minVal = getPeebles(v);
//         return;
//     }
//     for (const auto& [idx, type] : roots)
//     {
//         if (visited.find(v) != visited.end()) continue;
//         visited.insert(v);
     
//         if (type == 0) // left Move
//         {
//             v[idx - 1] = true;
//             v[idx] = v[idx + 1] = false;
//             vector<pair<int, int>> newRoots = getRoots(v);
         
//             dfs(v, newRoots, visited, minVal);
            
//             v[idx - 1] = false;
//             v[idx] = v[idx + 1] = true;
//         }
//         else // Right Move
//         {
//             v[idx] = v[idx - 1] = false;
//             v[idx + 1] = true;
//             vector<pair<int, int>> newRoots = getRoots(v);
            
//             dfs(v, newRoots, visited, minVal);
            
//             v[idx] = v[idx - 1] = true;
//             v[idx + 1] = false;
//         }
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false); 
//     cin.tie(0); cout.tie(0); 
//     int n;
//     cin >> n;
//     cin.ignore();
    
//     while (n--)
//     {
//         string s;
//         getline(cin, s);
        
//         vector<bool>v;
//         vector<pair<int, int>> roots;
//         unordered_set<vector<bool>> visited;
        
//         for (const char& c : s) v.push_back(c == 'o');
//         int minVal = numeric_limits<int>::max();
//         roots = getRoots(v);
        
//         dfs(v, roots, visited, minVal);
        
//         cout << (minVal == numeric_limits<int>::max() 
//             ? 0 : minVal ) << endl;
//     }
    
//     return 0;
// }