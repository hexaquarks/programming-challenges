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

double computeMax(int a, int b, int c, double R)
{
    return -a * pow(R, 2) + b * R + c;
}

int main()
{
    IOS;
    int tests;
    cin >> tests;
    while (tests--)
    {
        int n;
        cin >> n;

        pair<int, double> maxTorque = make_pair(1, 0);
        
        for (int i = 1; i <= n; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;
            double R = (double) b / (2 * (double) a);
            double T = computeMax(a, b, c, R);
            
            if (T > maxTorque.s) maxTorque = make_pair(i, T);
        }
        cout << maxTorque.f << endl;
    }

    return 0;
}