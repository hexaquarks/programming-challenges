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
    cin.ignore();
    vector<int> sums;
    string val;
    int currTot = 0, maxVal = -1;
    
    while (val != "-1")
    {
        getline(cin, val);
        if (val.empty())
        {
            sums.push_back(currTot);
            maxVal = max(maxVal, currTot);
            currTot = 0;
        }
        else currTot += stoi(val);
    }
    
    cout << endl << "Part 1 " << maxVal;
    
    sort(sums.rbegin(), sums.rend());
    maxVal = sums[0] + sums[1] + sums[2];
    cout << endl << "Part 2 " << maxVal;
    return 0;
}