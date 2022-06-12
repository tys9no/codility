// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    if (S.length() == 0) {
        return 1;
    }
    vector<char> stack = {};
    map<char, char> bracketsPairs = {{'(', ')'}, {')', '('}, {'{', '}'},
                                     {'}', '{'}, {'[', ']'}, {']', '['}};
    for (char s : S) {
        switch (s) {
            case '(':
            case '{':
            case '[':
                stack.push_back(s);
                break;
            case ')':
            case '}':
            case ']':
                if (stack.empty()) {
                    return 0;
                }
                if (stack.back() != bracketsPairs[s]) {
                    return 0;
                }
                stack.pop_back();
                break;
        }
    }
    if ((int)stack.size() > 0) {
        return 0;
    }
    return 1;
}