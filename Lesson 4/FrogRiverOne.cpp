// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> B(X);
    fill(B.begin(), B.end(), -1);

    int N = (int)A.size();
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int p = A[i] - 1;
        if (p < X && B[p] == -1) {
            B[p] = A[i];
            cnt++;
            if (cnt == X) {
                return i;
            }
        }
    }
    return -1;
}