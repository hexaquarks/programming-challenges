int solution(int n, int firstNumber) {
    return firstNumber + (firstNumber >= n / 2 ? -n : n) / 2;
}
