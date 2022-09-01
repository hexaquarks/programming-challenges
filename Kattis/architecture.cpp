#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int r, c, temp;
	cin >> r >> c;
	
	vector<int> rv, cv;
	while (r--) 
	{
	    cin >> temp;
	    rv.push_back(temp);
	}
	while (c--) 
	{
	    cin >> temp;
	    cv.push_back(temp);
	}
	if (*max_element(rv.begin(), rv.end()) == 
	    *max_element(cv.begin(), cv.end()))
	    {
	        cout << "possible" << endl;
	    }
    else cout << "impossible" << endl;
	return 0;
}

/* Better looking solution */
int main() 
{
	int r, c, temp;
	cin >> r >> c;
	
	int rv[r], cv[c];
	for (int i = 0; i < r; ++i) cin >> rv[i];
	for (int i = 0; i < c; ++i) cin >> cv[i];
	if (*max_element(rv, rv + r) == *max_element(cv, cv + c))
	{
		cout << "possible" << endl;
	}
    else cout << "impossible" << endl;
	return 0;
}