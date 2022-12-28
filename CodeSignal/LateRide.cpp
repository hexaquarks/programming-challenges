int countDigits(int n)
{
    int tot = 0;
    while (n)
    {
        tot += n % 10;
        n /= 10;
    }
    return tot;
}

int solution(int n) {
    int hours = n / 60;
    int minutes = n % 60;
    return countDigits(hours) + countDigits(minutes);
}
