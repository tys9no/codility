// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int max_ending = A[0];
    int max_slice = A[0];

    int N = (int)A.size();
    for (int i = 1; i < N; i++) {
        int tmp = max_ending + A[i];
        max_ending = (tmp > A[i]) ? tmp : A[i];
        max_slice = (max_ending > max_slice) ? max_ending : max_slice;
    }
    return max_slice;
}
