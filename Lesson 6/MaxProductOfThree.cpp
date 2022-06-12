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
    sort(A.begin(), A.end());
    int N = (int)A.size();
    int max1 = A[N - 1] * A[N - 2] * A[N - 3];
    int max2 = A[0] * A[1] * A[N - 1];
    return (max1 > max2) ? max1 : max2;
}
