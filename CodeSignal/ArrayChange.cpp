#include <vector>

using namespace std;

/* My solution */
int solution(vector<int> inputArray) 
{
    if (inputArray.size() == 0) return 0;
    int ans = 0;
    
    for (int i = 1; i < inputArray.size(); ++i)
    {
        if (inputArray[i] <= inputArray[i - 1]) 
        {
            int temp = inputArray[i - 1] + 1 - inputArray[i];
            ans += temp;
            inputArray[i] += temp;
        }
    }
    
    return ans;
}

/* Shorter solution */
int solution(std::vector<int> a) {
    int ma = -1e6;
    int ans = 0;
    for(int i:a)
    {
        ma = max(ma+1,i);
        ans += ma - i;
    }
    return ans;
}
