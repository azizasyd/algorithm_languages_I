#include <bits/stdc++.h>

using namespace std;

const int MAX_LIMIT = 50000000;

std::vector<bool> sieve_of_er(int max_limit) {
    std::vector<bool> is_prime(max_limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= max_limit; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::vector<bool> is_prime = sieve_of_er(MAX_LIMIT);

    for (int i = 0; i < n; ++i) {
        if (is_prime[numbers[i]]) {
            std::cout << 1;
        } else {
            std::cout << 0;
        }
    }
    std::cout << '\n';
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}