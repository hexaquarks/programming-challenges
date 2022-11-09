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

double calculate_area(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c)
{
    return abs((double)(a.f * (b.s - c.s)) + 
        (double)(b.f * (c.s - a.s)) + 
        (double)(c.f * (a.s - b.s))) / 2;
}

int main()
{
    IOS;
    vector<pair<int, int>> tri(3);
    for (int i = 0; i < 3; ++i)
    {   
        int a, b;
        cin >> a >> b;
        tri[i] = make_pair(a, b);
    }
    double triangleArea = calculate_area(tri[0], tri[1], tri[2]); 
    int n, tot = 0;
    cin >> n;
    vector<pair<int, int>> apple(n);
    for (int i = 0; i < n; ++i) 
    {
        int a, b;
        cin >> a >> b;
        apple[i] = make_pair(a, b);
    }
    
    for (pair<int,int>& a : apple)
    {
        double subTriangleA = calculate_area(a, tri[1], tri[2]);
        double subTriangleB = calculate_area(tri[0], a, tri[2]);
        double subTriangleC = calculate_area(tri[0], tri[1], a);
        if (subTriangleA + subTriangleB + subTriangleC == triangleArea) ++tot;
    }
    
    cout << fixed << setprecision(1) << triangleArea << endl;
    cout << tot;
    return 0;
}