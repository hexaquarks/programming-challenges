#include <vector>
#include <algorithm>

using namespace std;

/* my solution - faster than 20% */
int solve(vector<int>& tasks, vector<int>& people) 
{
    int n = people.size();
    if (n == 0) return 0;
    int m = tasks.size();
    if (m == 0) return 0;
    
    int counter = 0;
    std::sort(tasks.rbegin(), tasks.rend());
    std::sort(people.rbegin(), people.rend());

    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        while (j < m && people[i] < tasks[j]) ++j;
        if (j == m) return counter;
        else { ++counter; ++j; };
    }
    return counter;
}

/* better solution */
int solve(vector<int>& tasks, vector<int>& people) {
    sort(tasks.begin(), tasks.end());
    sort(people.begin(), people.end());
    int n = people.size();
    int n2 = tasks.size();
    if (n2 == 0) return 0;
    int i = 0;
    int j = 0;
    while (i < n2 && j < n) {
        if (tasks[i] <= people[j]) {
            i++;
            j++;
        } else
            j++;
    }
    return i;
}
