#include <bits/stdc++.h>
using namespace std;

int solution(int deposit, int rate, int threshold) {
    double d = (double) deposit;
    int i = 0;
    while (true)
    {
        d *= 1 + ((double)rate) / 100;
        if (d >= threshold) return i + 1;
        ++i;
    }
    return 0;
}
