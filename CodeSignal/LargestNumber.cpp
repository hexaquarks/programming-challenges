int solution(int n) {
    int ans = 9;
    while (--n)
    {
        ans *= 10;
        ans += 9;
    }
    return ans;
}
