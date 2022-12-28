int solution(int min1, int min2_10, int min11, int s) {
    int duration = 0;
    while (s >= 0)
    {
        if (duration == 0) {
            s -= min1;
        } else if (duration >= 1 && duration <= 9) {
            s -= min2_10;
        } else {
            s -= min11;
        }
        ++duration; 
    }
    return duration - 1;
}
