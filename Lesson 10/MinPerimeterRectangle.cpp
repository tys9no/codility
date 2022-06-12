// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int result = 1000000001 * 2;

    double sqrtRoot = sqrt(N);
    for (int i = 1; i <= sqrtRoot; i++) {
        if (N % i == 0) {
            int tmp = ((N / i) + i) * 2;
            result = min(tmp, result);
        }
    }

    return result;
}