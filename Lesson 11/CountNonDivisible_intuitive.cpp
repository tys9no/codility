// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    vector<int> counts(N * 2 + 1, 0);
    for (auto a : A) {
        counts[a]++;
    }

    vector<int> results;
    for (int i = 0; i < N; i++) {
        int cntNonDiv = 0;
        for (int j = 1; j < (int)counts.size(); j++) {
            if (counts[j] == 0) {
                continue;
            }
            if (A[i] % j != 0) {
                cntNonDiv += counts[j];
            }
        }
        results.push_back(cntNonDiv);
    }

    return results;
}
