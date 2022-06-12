// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)A.size();
    int cntForEast = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) {
            cntForEast += 1;
        } else {
            cnt += cntForEast;
            if (cnt > 1000000000) {
                return -1;
            }
        }
    }

    return cnt;
}
