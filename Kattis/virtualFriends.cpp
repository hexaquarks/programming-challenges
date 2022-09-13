#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

class UnionFind
{
public:
    UnionFind(int n)
    {
        parents.assign(n, 0);
        rank.assign(n, 0);
        size.assign(n, 1);
        for (int i = 0; i < n; ++i) parents[i] = i;
    }
    
    int find(int i)
    {
        if (parents[i] == i) return i;
        else return parents[i] = find(parents[i]);
    }
    
    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        
        if (x == y) return; // isSameSet
        if (rank[x] < rank[y]) swap(x, y); //heuristic
        
        parents[y] = x;
        if (rank[x] == rank[y]) ++rank[x];
        size[x] += size[y];
    }
    
    int getIndex(unordered_map<string, int>& mem, string& s)
    {
        if (!mem.count(s)) mem[s] = count++;
        return mem[s];
    }
    
    int getSize(int i)
    {
        return size[find(i)];
    }
private:
    vector<int> parents, rank, size;
    int count = 0;
};

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    
    int n;
    cin >> n;
    while (n--)
    {
        int f;
        cin >> f;
        
        UnionFind u(201000);
        unordered_map<string, int> mem;
        
        while (f--)
        {
            string f1, f2;
            cin >> f1 >> f2;
            int idx1 = u.getIndex(mem, f1);
            int idx2 = u.getIndex(mem, f2);
            
            u.unite(idx1, idx2);
            cout << u.getSize(idx1) << endl;
        }
    }
    return 0;
}