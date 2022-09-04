#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0) break;
        
        vector<int> key;
        int temp = n;
        while (temp--)
        {
            int num;
            cin >> num;
            key.push_back(num);
        }
        cin.ignore();

        string message;
        getline(cin, message);
        
        // resizing
        int rem = message.size() % n;
        if (rem > 0) message.append(n - rem, ' ');

        // Run the algo
        string ans;
        cout << "'";
        for (int i = 0; i < message.size() / n; ++i)
        {
            for (const int num : key) 
            {
                ans += message[(num - 1) + i * n];
            }
        }
        cout << ans << "'" << endl;
    }
    return 0;
}