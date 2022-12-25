#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> inputArray) 
{
    sort(inputArray.begin(), inputArray.end());
    
    int jumpDist = 1;
    bool obstacleHit = true;
    
    while (obstacleHit)
    {
        obstacleHit = false;
        ++jumpDist;
        
        for (int i = 0; i < inputArray.size(); ++i)
        {
            if (inputArray[i] % jumpDist == 0) 
            {
                obstacleHit = true;
                break;
            }
        }
    }
    return jumpDist;
}