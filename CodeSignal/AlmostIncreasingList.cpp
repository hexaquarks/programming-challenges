#include <vector>

using namespace std;

/* Popular question, just gotta learn this by heart */
bool solution(vector<int> sequence) 
{
    int prev = sequence[0];
    bool used = false;
    for (int i = 1; i < sequence.size(); ++i)
    {
        int curr = sequence[i];
        if (curr <= prev)
        {
            if (used) return false;
            used = true;
            if (i == 1 || sequence[i] > sequence[i - 2]) prev = sequence[i];
        }
        else prev = curr;    
    }
    return true;
}
