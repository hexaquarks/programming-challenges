#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

int main()
{
    ios::sync_with_stdio(false);
    int q;
    cin >> q;

    while (q--)
    {
        int n;
        cin >> n;
        string out = "";
        for (int i = 0; i < n; ++i)
        {
            char c;
            cin >> c;

            if (c == '0')
            {
                if (i + 1 < n)
                {
                    char d;
                    cin >> d;
                    if (d == '0')
                    {
                        char first = out[out.size() - 1];
                        out.pop_back();
                        int tot = (first - '0') * 10;
                        char totC = (char)('a' + tot - 1);
                        out += totC;
                    }
                    else 
                    {
                        char first = out[out.size() - 1];
                        out.pop_back();
                        char second = out[out.size() - 1];
                        out.pop_back();
                        int tot = (first - '0') * 10 + (second -'0');
                        char totC = (char)('a' + tot - 1);
                        out += totC;

                        out += to_string(static_cast<int>(d - 96));
                        ++i;
                    }
                }
                else
                {
                    char first = out[out.size() - 1];
                    out.pop_back();
                    char second = out[out.size() - 1];
                    out.pop_back();
                    int tot = (first - '0') * 10 + (second -'0');
                    char totC = (char)('a' + tot - 1);
                    out += totC;
                }
            }
            else
            {
                out += to_string(static_cast<int>(c - 96));
            }

        }
    }
   
    return 0;
}