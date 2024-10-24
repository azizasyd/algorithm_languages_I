#include <bits/stdc++.h>

using namespace std;

long long lcm(long long a, long long b) {
    return a / std::gcd(a, b) * b;
}

void solve() {
    long long n;
    int k;
    std::cin >> n >> k;

    long long ten_pow_k = std::pow(10, k);
    long long result = lcm(n, ten_pow_k);

    std::cout << result << "\n";
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
