#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    
    int W, N;
    cin >> W >> N;
    int tot = 0;
    while (N--)
    {
        int w, l;
        cin >> w >> l;
        tot += w * l;
    }
    cout << (tot / W);
    return 0;
}