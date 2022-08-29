#include <vector>
#include <algorithm>

using namespace std; 

int solution(vector<int> statues) 
{
    
    int maxVal = 0, minVal = numeric_limits<int>::max();
    int count = 0;
    
    for (const int val : statues)
    {
        maxVal = max(maxVal, val);
        minVal = min(minVal, val);
        ++count;
    }
    if (maxVal == minVal) return 0;
    else return maxVal - minVal - count + 1;
}

/* WOW, minmax in c++ !! */
int solution(std::vector<int> statues) {
    auto x = minmax_element(begin(statues),end(statues));
    return *x.second-*x.first-statues.size()+1;
}