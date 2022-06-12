// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <vector>

using namespace std;

vector<int> GetFactors(int N) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> factors(N + 1, 0);
    int i = 2;
    for (int i = 2; i * i < N; i++) {
        if (factors[i] == 0) {
            int k = i * i;
            while (k < N) {
                if (factors[k] == 0) {
                    factors[k] = i;
                }
                k += i;
            }
        }
    }
    return factors;
}

vector<int> GetPrimeFactors(int x, vector<int> factors) {
    vector<int> primeFactors;
    while (factors[x] > 0) {
        primeFactors.push_back(factors[x]);
        x /= factors[x];
        primeFactors.push_back(x);
    }
    return primeFactors;
}
