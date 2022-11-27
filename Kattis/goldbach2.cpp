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

bool isPrime(int i)
{
    for (int j = 2; j * j <= i; ++j)
    {
         if (i % j == 0)
         {
             return false;
         }
    }
    return true;
}

int main()
{
    IOS;
    int test;
    cin >> test;
    while (test--)
    {
        int val;
        cin >> val;
        
        vector<int> primes;
        vector<pair<int, int>> vals;
        
        for (int i = 2; i <= val; ++i)
        {   
            if (isPrime(i) && isPrime(val - i) && val - i != 1 && i <= val - i) 
            {
                vals.push_back(make_pair(i, val - i));
            }
        }
        
        cout << val << " has " << vals.size() << " representation(s)" << endl;
        for (const pair<int, int>& p : vals) cout << p.f << "+" << p.s << endl;
        cout << endl;
    }

    return 0;
}