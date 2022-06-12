// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    int eleMax = *max_element(A.begin(), A.end()) + 1;

    vector<int> counts(eleMax, 0);
    for (auto a : A) {
        counts[a]++;
    }

    vector<int> results;
    for (int i = 0; i < N; i++) {
        int cntDiv = 0;
        for (int j = 1; j * j <= A[i]; j++) {
            if (A[i] % j == 0) {
                cntDiv += counts[j];
                if (A[i] / j != j) {
                    cntDiv += counts[A[i] / j];
                }
            }
        }
        results.push_back(N - cntDiv);
    }

    return results;
}
