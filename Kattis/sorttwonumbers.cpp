#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int x ,y;
    cin >> x >> y;
    
    cout << ((x > y) ? y : x) << " ";
    cout << ((x > y) ? x : y) << endl;
    return 0;
}

// More cool solution 
int main() 
{
    int x ,y;
    cin >> x >> y;
    
    std::cout << std::min(x, y) << " " << std::max(x, y) << std::endl;
    return 0;
}
