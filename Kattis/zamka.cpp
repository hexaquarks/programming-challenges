#include <bits/stdc++.h>
using namespace std;

int getSum(int n)
{
    int sum = 0;
    while (n != 0) 
    {
        sum += n % 10; 
        n /= 10;
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    int l, d, x;
    cin >> l >> d >> x;
    
    for (int i = l; i <= d; ++i)
    {
        if (getSum(i) == x) { cout << i << endl; break; }
    }
    
    for (int i = d; i >= l; --i)
    {
        if (getSum(i) == x) { cout << i; break; }
    }
    return 0;
}