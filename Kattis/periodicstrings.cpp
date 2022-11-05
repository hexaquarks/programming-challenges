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

template<typename T>
void printVector(const T& t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
}

vector<string> getStrings(string& s, int size)
{
    int numSub = s.size() / size;
    vector<string> strings(numSub);
    
    for (int i = 0; i < numSub; ++i)
    {
        strings[i] = s.substr(i * size, size);
    }
    
    return strings;
}

int main()
{
    IOS;
    string s;
    getline(cin, s);
    int strSize = s.size();
    for (int i = 1; i < strSize; ++i)
    {
        if (strSize % i != 0) continue;
        vector<string> subStrings = getStrings(s, i);
        
        string prev = subStrings[0];
        bool isGood = true;
        for (int i = 1; i < subStrings.size(); ++i)
        {
            string copy(prev); 
            std::rotate(copy.rbegin(), copy.rbegin() + 1, copy.rend());
            
            if (subStrings[i] != copy)
            {
                isGood = false;
                break;
            }
            prev = copy;
        }
        if (isGood) 
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << strSize << endl;
    return 0;
}