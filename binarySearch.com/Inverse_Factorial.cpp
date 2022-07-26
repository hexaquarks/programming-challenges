int solve(int a) 
{
    int curr = 1;
    while (a > curr)
    {
        if (a % curr) return -1;
        a /= curr;
        ++curr;
    }
    if (curr == a) return curr;
    return -1;
}