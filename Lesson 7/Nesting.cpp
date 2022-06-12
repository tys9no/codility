// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <vector>

using namespace std;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    if (S.length() == 0) {
        return 1;
    }
    if (S[0] == ')') {
        return 0;
    }
    vector<char> nests;
    for (auto s : S) {
        switch (s) {
            case '(':
                nests.push_back(s);
                break;
            case ')':
                if (nests.empty()) {
                    return 0;
                }
                if (nests.back() == '(') {
                    nests.pop_back();
                }
                break;
        }
    }
    if (nests.empty()) {
        return 1;
    }
    return 0;
}
