#include <vector>
using namespace std;

int solve(vector<string>& words) 
{
    int n = words.size();
    if (n == 0) return 0;

    int last = 0, max = 1;
    
    for (int i = 1; i < n; ++i)
    {
        if (words[i][0] != words[last][0]) last = i; 
        else max = std::max(max, (i - last + 1));
    }
    
    return max;
}
