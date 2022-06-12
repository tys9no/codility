// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &H) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)H.size();
    int stones = 0;
    vector<int> stack;

    for (int i = 0; i < N; i++) {
        while (((int)stack.size() > 0) && (stack.back() > H[i])) {
            stack.pop_back();
        }
        if (((int)stack.size() > 0) && (stack.back() == H[i])) {
            // すでに積んでる、かつブロックの高さが一緒なら無視。
            continue;
        } else {
            // 石を積む
            stones++;
            stack.push_back(H[i]);
        }
    }

    return stones;
}
