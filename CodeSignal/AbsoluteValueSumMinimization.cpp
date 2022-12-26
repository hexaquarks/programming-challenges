#include <bits/stdc++.h>
using namespace std;

int computeSum(const vector<int>& v, int x)
{
    int tot = 0;
    for (int a : v) tot += abs(a - x);
    return tot;
}

int solution(vector<int> a) {
    int minVal = numeric_limits<int>::max();
    int ans = -1;
    for (int x : a) 
    {
        int newSum = computeSum(a, x);
        if (newSum < minVal) ans = x;
        minVal = min(minVal, newSum);
    }
    return ans;
}
