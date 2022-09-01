#include <bits/stdc++.h>
using namespace std;

int main() 
{
	string n;
	cin >> n;
	
	int i = 0;
	while(n[i] == '|') ++i;
	cout << ((n.size() - i - 2 == i) ? "correct" : "fix") << endl;
	return 0;
}