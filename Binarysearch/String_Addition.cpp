#include <string>

using namespace std;

string solve(string a, string b) 
{
    if (a.size() > b.size()) std::swap(a, b);
    int sizeA = a.size(), sizeB = b.size();

    string ans = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
 
    int carry = 0;
    for (int i = 0; i < sizeA; ++i)
    {
        int sum = ((a[i]-'0') + (b[i]-'0') + carry);
        ans.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
 
    for (int i = sizeA; i < sizeB; ++i)
    {
        int sum = ((b[i]-'0') + carry);
        ans.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
 
    if (carry) ans.push_back(carry + '0');
    reverse(ans.begin(), ans.end());
 
    return ans;
}
