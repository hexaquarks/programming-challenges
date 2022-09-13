#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    int n;
    while (cin >> n)
    {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool isQ = true, isPQ = true, isS = true;
        
        while (n--)
        {
            int a, b;
            cin >> a >> b;
            
            if (a == 1)
            {
                s.push(b);
                q.push(b);
                pq.push(b);
            }
            else
            {
                if (q.empty() || q.front() != b) isQ = false;
                if (pq.empty() || pq.top() != b) isPQ = false;
                if (s.empty() || s.top() != b) isS = false;
                
                if (!q.empty()) q.pop();
                if (!pq.empty()) pq.pop();
                if (!s.empty()) s.pop();
            }
        }
        if (isQ + isPQ + isS > 1) cout << "not sure";
        else if (!isQ && !isPQ && !isS) cout << "impossible";
        else if (isQ) cout << "queue";
        else if (isPQ) cout << "priority queue";
        else if (isS) cout << "stack";
        cout << endl;
    }
    return 0;
}