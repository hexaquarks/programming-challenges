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

int main()
{
    IOS;
    long long a, b;
    while (cin >> a >> b)
    {
        long long diff = abs(a - b);
        cout << diff << endl;
    }

    return 0;
}