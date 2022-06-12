// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int GetLeader(vector<int> &A) {
    if (A.empty()) {
        return -1;
    }

    // dominator検索
    vector<int> stack;
    for (auto a : A) {
        if (stack.empty()) {
            stack.push_back(a);
        } else if (stack.back() == a) {
            stack.push_back(a);
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

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int count = 0;
    if (A.empty()) {
        return count;
    }
    int idx = GetLeader(A);
    if (idx == -1) {
        return count;
    }
    int leader = A[idx];
    int cnt = 0;
    for (auto a : A) {
        if (leader == a) {
            cnt++;
        }
    }
    if (cnt <= (int)A.size() / 2) {
        return 0;
    }

    // let's count the number of equi leader.
    int lcnt = 0;  // leader appeard until the index.
    for (int i = 0; i < (int)A.size(); i++) {
        if (A[i] == leader) {
            lcnt++;
        }
        // check if the current index is a equi leader
        int lelems = i + 1;
        if ((lcnt > lelems / 2) &&
            ((cnt - lcnt) > ((int)A.size() - lelems) / 2)) {
            count++;
        }
    }

    return count;
}
