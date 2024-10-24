#include <bits/stdc++.h>

using namespace std;

bool is_prime(long long x) {
    if (x < 2) {
        return false;
    }
    if (x == 2 || x == 3) {
        return true;
    }
    if (x % 2 == 0) {
        return false;
    }
    for (long long i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        long long X;
        std::cin >> X;

        if (is_prime(X)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}