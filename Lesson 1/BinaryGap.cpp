// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    bitset<32> bs(N);
    string bsStr = bs.to_string();
    vector<int> idx;
    for (int i = 0; i < (int)bsStr.length(); i++) {
        if (bsStr[i] == '1') {
            idx.push_back(i);
        }
    }

    int max = 0;
    int count = 0;
    for (int i = 0; i < (int)idx.size() - 1; i++) {
        int start = idx[i];
        int end = idx[i + 1] - idx[i];
        count = bsStr.substr(start, end).length() - 1;
        if (count > max) {
            max = count;
        }
    }
    return max;
}
