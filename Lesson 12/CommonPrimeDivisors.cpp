// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int a = A[i];
        int b = B[i];
        int d = gcd(a, b);
        while (gcd(a, d) != 1) {
            a /= gcd(a, d);
        }
        while (gcd(b, d) != 1) {
            b /= gcd(b, d);
        }
        if (a == 1 && b == 1) {
            cnt++;
        }
    }
    return cnt;
}