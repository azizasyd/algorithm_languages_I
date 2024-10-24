#include <bits/stdc++.h>

void solve() {
    int n;
    long long s;
    std::cin >> n >> s;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int l = 0;
    long long current_sum = 0;
    int max_len = 0;

    for (int r = 0; r < n; r++) {
        current_sum += a[r];

        while (current_sum > s) {
            current_sum -= a[l];
            l++;
        }
        max_len = std::max(max_len, r - l + 1);
    }
    std::cout << max_len << "\n";
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}