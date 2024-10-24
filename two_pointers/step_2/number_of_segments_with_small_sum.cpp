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
    long long good_s = 0;

    for (int r = 0; r < n; r++) {
        curr_sum += a[r];

        while (curr_sum > s) {
            curr_sum -= a[l];
            l++;
        }

        good_s += (r - l + 1);
    }
    std::cout << good_s << "\n";
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}