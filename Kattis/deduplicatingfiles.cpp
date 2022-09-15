#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

int hashF(const string& s)
{
    int tot = 0;
    for (const auto& c : s) tot ^= c;
    return tot;
}

int traversePermutations(unordered_map<string, int>& mem)
{
    int tot = 0;
    for (const auto& [key1, val1] : mem)
    {
        int firstH = hashF(key1);
        for (const auto& [key2, val2] : mem)
        {
            if (key1 == key2) continue;
            int secondH = hashF(key2);
            if (firstH == secondH) tot += val1 * val2;
        }
    }
    return tot;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    
    int n;
    while (cin >> n && n)
    {
        cin.ignore();
        
        int tot = 0;
        unordered_map<string, int> mem;
        
        while (n--)
        {
            string s;
            getline(cin, s);
            ++mem[s];
        }
    
        tot = traversePermutations(mem);
        cout << mem.size() << " " << (tot >> 1) << "\n";
    }
    return 0;
}