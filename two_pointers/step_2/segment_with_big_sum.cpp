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
    long long curr_sum = 0;
    int min_len = n + 1;

    for (int r = 0; r < n; r++) {
        curr_sum += a[r];
        while (curr_sum >= s) {
            min_len = std::min(min_len, r - l + 1);
            curr_sum -= a[l];
            l++;
        }
    }
    if (min_len == n + 1) {
        std::cout << -1 << "\n";
    } else {
        std::cout << min_len << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}