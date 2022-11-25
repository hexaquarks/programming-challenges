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

template<typename T>
void printVector(const T& t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
}

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2));
}
int main()
{
    IOS;
    pair<int, int> origin; 
    int x ,y, n;
    cin >> x >> y >> n;
    origin = make_pair(x, y);

    vector<double> currDists;
    while (n--)
    {
        int a, b, r;
        cin >> a >> b >> r;
        int len = dist(x, y, a, b) - r;
        
        currDists.push_back(len);
    }
    sort(currDists.begin(), currDists.end());
    if (currDists[0] < 0 && currDists[1] < 0 && currDists[2] < 0) 
    {
        cout << 0;
        return 0;
    }
    cout << currDists[2] << endl;
    return 0;
}