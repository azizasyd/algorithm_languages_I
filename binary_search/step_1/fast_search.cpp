#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n; // 5

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    int k;
    std::cin >> k;

    // 1 3 4 10 10
    std::vector<int> results;
    for (int i = 0; i < k; ++i) {
        int l, r;
        std::cin >> l >> r;

        // 1st position where v >= l
        // 1st position where v > r

        // lower bound = 1st after num
        // upper bound = 1st after num (not included, e.g. num itself)
        auto low = std::lower_bound(a.begin(), a.end(), l);
        auto high = std::upper_bound(a.begin(), a.end(), r);

        results.push_back(high - low);
    }

    for (int i = 0; i < k; ++i) {
        std::cout << results[i] << " ";
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}