// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.empty()) {
        return -1;
    }

    // dominator検索
    vector<int> B;
    copy(A.begin(), A.end(), back_inserter(B));
    sort(B.begin(), B.end());

    vector<int> stack;
    for (auto b : B) {
        if (stack.empty()) {
            stack.push_back(b);
        } else if (stack.back() == b) {
            stack.push_back(b);
        } else {
            stack.pop_back();
        }
    }

    if (stack.empty()) {
        return -1;
    }

    int cnt = count(A.begin(), A.end(), stack[0]);
    if (cnt <= A.size() * 0.5) {
        return -1;
    }

    return distance(A.begin(), find(A.begin(), A.end(), stack[0]));
}
