#include <string>
#include <vector>

using namespace std;

/* My solution */
bool solution(string inputString) 
{
    vector<int> mem(26, 0);
    int ans = 0;
    
    for (const char& c : inputString) ++mem[c - 'a'];
    for (int i = 0; i < 26; ++i)
    {
        if (mem[i] % 2 != 0) ++ans;
    }
    return ans == 1 || ans == 0;
}

/* Bitwise solution, cool */
int A[256];
bool solution(std::string inputString) {
    for(char i:inputString)
        ++A[i];
    int c = 0;
    for(int i = 0; i < 256; ++i)
        c += A[i]&1;
    return c<2;
}
