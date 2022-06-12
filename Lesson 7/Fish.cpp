// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> ds;
    int eatenCnt = 0;
    for (int i = 0; i < (int)B.size(); i++) {
        if (B[i]) {
            ds.push_back(A[i]);
        } else {
            while (!ds.empty()) {
                if (ds.back() > A[i]) {
                    // 下流の魚に食べられた
                    eatenCnt++;
                    break;
                } else if (A[i] > ds.back()) {
                    // 上流の魚が食べた
                    eatenCnt++;
                    // 下流の魚をへらす。
                    ds.pop_back();
                }
            }
        }
    }
    return (int)A.size() - eatenCnt;
}
