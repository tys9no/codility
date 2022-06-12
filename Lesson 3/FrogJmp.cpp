// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <cmath>
using namespace std;
int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    int count = 0;
    if (X > Y) {
        return count;
    }
    count = (abs((Y - X)) / D);
    if ((abs((Y - X)) % D) == 0) {
        return count;
    } else {
        return count + 1;
    }
}