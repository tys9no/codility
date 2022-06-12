// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <vector>

using namespace std;

vector<int> GetPrimes(int N) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> primes(N + 1, 1);
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i * i <= N; i++) {
        if (primes[i]) {
            int k = i * i;
            while (k <= N) {
                primes[k] = 0;
                k += i;
            }
        }
    }
    return primes;
}

vector<bool> GetAllSemiPrimes(vector<int> &primes) {
    // write your code in C++14 (g++ 6.2.0)
    int N = (int)primes.size();
    vector<bool> allSemiPrimes(N, false);
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i * j > N) {
                break;
            }
            if (primes[i] * primes[j]) {
                if (i * j <= N) {
                    allSemiPrimes[i * j] = 1;
                }
            }
        }
    }
    return allSemiPrimes;
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> primes = GetPrimes(N);
    vector<bool> allSemiPrimes = GetAllSemiPrimes(primes);

    vector<int> semiPrimes(P.size(), 0);
    vector<int> semiPrimesScum(N + 1, 0);
    int cnt = 0;
    for (int i = 0; i <= N; i++) {
        cnt += allSemiPrimes[i];
        semiPrimesScum[i] = cnt;
    }
    for (int i = 0; i < (int)P.size(); i++) {
        semiPrimes[i] = semiPrimesScum[Q[i]] - semiPrimesScum[P[i] - 1];
    }
    return semiPrimes;
}
