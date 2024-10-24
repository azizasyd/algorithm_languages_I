#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> w[i];
    }

    int min_b = INT_MAX;
    std::vector<int> best_subset;


    for (int mask = 1; mask < (1 << n); ++mask) {
        int b = 0;
        std::vector<int> curr_s;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                curr_s.push_back(i + 1);
                if (curr_s.size() % 2 == 1) {
                    b += w[i];
                } else {
                    b -= w[i];
                }
            }
        }

        if (abs(b) < min_b) {
            min_b = abs(b);
            best_subset = curr_s;
        }
    }

    std::cout << min_b << "\n";
    std::cout << best_subset.size() << "\n";
    for (int idx : best_subset) {
        std::cout << idx << " ";
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}