#include <bits/stdc++.h>
using namespace std;

#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define f first
#define s second
#define endl "\n"

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

bool verifyDirection(vector<double>& dir, double w, int lim) 
{
    sort(dir.begin(), dir.end());
	int last = dir.size() - 1;
	
	for (int i = 0; i < last; ++i)
	{
		if (dir[i] + w < dir[i + 1]) return false;
	}
	if (dir[last] < lim - w / 2) return false;
	
	return true;
}

int main()
{
    IOS;
    while (true)
    {
        int nx, ny;
        double w;
        cin >> nx >> ny >> w;
        if (nx == 0 && ny == 0 && w == 0.0) break;
        
        vector<double> horizontal(nx), vertical(ny);
        for (int i = 0; i < nx; ++i) cin >> horizontal[i];
        for (int i = 0; i < ny; ++i) cin >> vertical[i];
        
        bool isOk = verifyDirection(horizontal, w, 75);
        if (!isOk) 
        {
            cout << "NO" << endl;
            continue;
        }
        isOk = verifyDirection(vertical, w, 100);
        if (!isOk) 
        {
            cout << "NO" << endl;
        } 
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}