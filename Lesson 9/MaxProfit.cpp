// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int max_ending = 0;
    int max_slice = 0;

    int diff = 0;
    for (int i = 0; i < (int)A.size() - 1; i++) {
        diff = A[i + 1] - A[i];
        max_ending = max(0, max_ending + diff);
        max_slice = max(max_slice, max_ending);
    }
    return max_slice;
}
