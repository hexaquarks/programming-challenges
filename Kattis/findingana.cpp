#include <bits/stdc++.h>
using namespace std;

int main()
{
    string in;
    cin >> in;
    
    int i = 0;
    for (; i < in.size(); ++i)
    {
        if (in[i] == 'a') break;
    }
    cout << in.substr(i, in.size() - i) << endl;
	return  0;
}

/* Much better */
int main()
{
    string in;
    cin >> in;
    
    cout << in.substr(in.find('a')) << endl;
	return  0;
}
