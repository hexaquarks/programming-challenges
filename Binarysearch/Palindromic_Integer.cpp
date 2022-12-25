#include <string>

using namespace std;

/* My solution (faster than 98.8 % of c++ submissions) */
// bool solve(int num) 
// {
//     string s = to_string(num);
//     int n = s.size();
//     if (n == 0) return true;

//     int middle, l, r;

//     if (n % 2 == 0) 
//     {
//         l = n / 2 - 1;
//         r = l + 1;
//     }
//     else 
//     {
//         middle = n / 2;
//         l = middle - 1;
//         r = middle + 1;
//     }

//     while (l >= 0 && r <= n - 1)
//     {
//         if (s[l] != s[r]) return false;
//         --l; ++r;
//     }
//     return true;
// }

/* Proposed solution (without using std::string) */
bool solve(int num) 
{
    int new_number = 0;
    int temp = num;

    while (temp != 0) 
    {
        int last_digit = temp % 10;
        temp /= 10;
        new_number = last_digit + (new_number * 10);
    }
    return num == new_number;
}