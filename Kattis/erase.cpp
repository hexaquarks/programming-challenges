#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    string first, second;
    cin >> first >> second;
    
    bool success = true;
    cout << "Deletion ";
    if (n % 2 == 0)
    {
        if (first == second) success = true;
        else success = false;
    }
    else
    {
        for (int i = 0; i < first.size(); ++i)
        {
            if (first[i] == second[i]) 
            {
                success = false;
                break;
            }
        }
    }
    cout << (success ? "succeeded" : "failed");
    return 0;
}