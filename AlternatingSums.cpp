#include <vector>

using namespace std;

/* My solution */
vector<int> solution(vector<int> a) 
{
    int i = 0, totA = 0, totB = 0;
    for (const int val : a)
    {
        if (i % 2 == 0) totA += a[i];
        else totB += a[i];
        ++i;
    }
    return {totA, totB};
}

/* Even simpler ! */
std::vector<int> solution(std::vector<int> a) {
    vector<int> ret(2);
    for(int i=0; i<a.size(); ++i)
        ret[i%2] += a[i];
    
    return ret;
}
