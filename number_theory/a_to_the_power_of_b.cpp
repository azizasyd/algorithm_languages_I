#include <bits/stdc++.h>

using namespace std;

long long mod_exp(long long A, long long B, long long M) {
    if (M == 1) {
        return 0;
    }
    long long result = 1;
    A = A % M;

    while (B > 0) {
        if (B % 2 == 1) {
            result = (result * A) % M;
        }
        A = (A * A) % M;
        B = B / 2;
    }
    return result;
}

void solve() {
    long long A, B, M;
    cin >> A >> B >> M;

    if (B == 0) {
        cout << 1 % M << "\n";
        return;
    }

    cout << mod_exp(A, B, M) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}


