#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    
    vector<int> stops;
    while (n--)
    {
        int val;
        cin >> val;
        stops.push_back(val);
    }
    sort(stops.begin(), stops.end());
    // 141 145 143 150
    for (int i = 0; i < stops.size(); ++i)
    {
        int left = stops[i];
        while (i + 1 < stops.size() && stops[i + 1] == stops[i] + 1)
        {
            ++i;
        }
        int right = stops[i];
        if (left != right)
        {
            if (right == left + 1)
            {
                --i;
                cout << left << " ";
            }
            else cout << left << "-" << right << " ";
        }
        else 
        {
            cout << left << " ";
        }
    }
    return 0;
}