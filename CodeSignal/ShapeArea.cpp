/* My solution */
int solution(int n) 
{
    if (n == 0) return 0;
    int prev = 1, i = 0, ans = 0;
    while (i < n)
    {
        ans = prev + 4 * i;
        prev = ans;
        ++i;
    }
    return ans;
}

/* Much better solution */
int solution(int n) {
    return 1 + 2 * n * (n-1);
}
