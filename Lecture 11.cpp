#include <bits/stdc++.h>
using namespace std;

long BinomialCoefficient(long N, long R) {
    vector<vector<long>> Coeff(N + 1, vector<long>(R + 1, 0));

    for (long n = 0; n <= N; n++) {
        for (long r = 0; r <= min(n, R); r++) {
            if (n == 0 || r == 0){
                Coeff[n][r] = 1;
            } else {
                Coeff[n][r] = Coeff[n - 1][r] + Coeff[n - 1][r - 1];
            }
        }
    }
    return Coeff[N][R];
}

int main() {
    
    return 0;
}