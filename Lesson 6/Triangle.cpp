// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.empty()) {
        return 0;
    }
    int N = (int)A.size();
    if (N < 3) {
        return 0;
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < N - 2; i++) {
        // オーバーフロー対策: a + b > c => a > c - b
        if (A[i] > (A[i + 2] - A[i + 1])) {
            return 1;
        }
    }
    return 0;
}