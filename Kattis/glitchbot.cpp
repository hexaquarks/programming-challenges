#include <bits/stdc++.h>
using namespace std;

#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define PI 3.14159265358979323846
#define f first
#define s second
#define endl "\n"

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

bool test(vector<string>& inst, int line, string newString, pair<int, int>& ans)
{
    vector<string> newInst(inst);
    newInst[line] = newString;
    double ang = 90;
    pair<double, double> pos = make_pair(0, 0);
    
    for (string& inst : newInst)
    {
        if (inst == "Forward") {
            double rad = ang * (double) (PI / 180);
            pos.f += cos(rad);
            pos.s += sin(rad);
        } else if (inst == "Right") {
            ang -= 90;
        } else if (inst == "Left") {
            ang += 90;
        }
        ang = fmod(ang, (ang < 0) ? -360 : 360);
    }

    
    if ((int)(round(pos.f)) == ans.f && (int)(round(pos.s)) == ans.s) return true;
    return false;
}

int main()
{
    IOS;
    int a, b;
    cin >> a >> b;
    pair<int, int> destination = make_pair(a, b);
    int n;
    cin >> n;
    
    vector<string> instructions;
    while (n--)
    {
        string dir;
        cin >> dir;
        instructions.push_back(dir);
    }
    vector<string> dirs{"Forward" , "Right", "Left"};
    for (int i = 0; i < instructions.size(); ++i)
    {
        for (string& dir : dirs)
        {
            if (instructions[i] == dir) continue;
            if (test(instructions, i, dir, destination)) 
            {
                cout << (i + 1) << " " << dir;
                return 0;
            }
        }
    }
    return 0;
}