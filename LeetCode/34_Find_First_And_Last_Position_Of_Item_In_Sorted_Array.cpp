#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& N, int T) {
        int first = find(T, N);
        if (first == N.size() || N[first] != T) return { -1, -1 };
        return { first, find(T+1, N, first) - 1 };
    }
    int find(int target, vector<int> arr, int left = 0) {
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1; // faster than division
            if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};