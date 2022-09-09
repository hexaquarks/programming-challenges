#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> inputArray) 
{
    int prev = inputArray[0], maxVal = 0;
    for (int i = 1; i < inputArray.size(); ++i)
    {
        maxVal = max(maxVal, abs(inputArray[i] - prev));
        prev = inputArray[i];
    }
    return maxVal;
}
