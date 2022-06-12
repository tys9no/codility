// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <vector>

using namespace std;
vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.empty()) {
        return A;
    }
    int tmp = 0;
    auto it = A.begin();
    for (int i = 0; i < K; i++) {
        tmp = A.back();
        A.pop_back();
        A.insert(it, tmp);
    }
    return A;
}