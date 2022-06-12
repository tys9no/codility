// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int sum = 0;
    for (auto a : A) {
        sum += a;
    }
    int sumPart1 = A[0];
    int sumPart2 = sum - sumPart1;
    int diff = abs(sumPart1 - sumPart2);
    if (diff == 0) {
        return 0;
    }
    int N = (int)A.size();
    int min = diff;
    for (int i = 1; i < N - 1; i++) {
        sumPart1 += A[i];
        sumPart2 -= A[i];
        diff = abs(sumPart1 - sumPart2);
        if (diff == 0) {
            return 0;
        }
        if (diff < min) {
            min = diff;
        }
    }
    return min;
}