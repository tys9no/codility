// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());

    int N = (int)A.size();

    auto itr = unique(A.begin(), A.end());
    A.erase(itr, A.end());
    if ((int)A.size() != N) {
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (A[i] != i + 1) {
            return 0;
        }
    }
    return 1;
}