#include <bits/stdc++.h>

void solve() {
    int n;
    long long s;
    std::cin >> n >> s;
    std::vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    long long current_sum = 0;
    int left = 0;
    long long count = 0;

    for (int right = 0; right < n; ++right) {
        current_sum += a[right];

        while (current_sum >= s) {
            count += (n - right);
            current_sum -= a[left];
            left++;
        }
    }
    std::cout << count << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
