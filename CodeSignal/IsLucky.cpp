#include <string>
#include <numeric>

using namespace std;

/* My solution */
bool solution(int n) 
{
    string num = to_string(n);
    int size = num.size();
    int firstNum = 0, secondNum = 0;
    
    for (int i = 0; i < size / 2; ++i)
    {
        firstNum += num[i] - '0';
        secondNum += num[size - 1 - i] - '0';
    }
    return firstNum == secondNum;
}

/* Cute solution */
bool solution(int n) {
    string s = to_string(n);
    auto half = s.begin() + s.size() / 2;
    return accumulate(s.begin(), half, 0) == accumulate(half, s.end(), 0);
}
