#include <vector>
#include <limits>

using namespace std;

/* My solution */
int solution(vector<int> inputArray) 
{
    if (inputArray.size() == 0) return 0;
    int maxVal = numeric_limits<int>::min();
    int prev = inputArray[0];
    for (int i = 1; i < inputArray.size(); ++i)
    {
        maxVal = max(maxVal, inputArray[i] * prev);
        prev = inputArray[i];
    }
    return maxVal;
}

