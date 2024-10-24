#include <bits/stdc++.h>
// NOT PASSED

void solve() {
    int n;
    std::cin >> n; // 2

    std::vector<std::pair<int, int>> vect(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vect[i].first >> vect[i].second;  // ai, bi
    }
    sort(vect.begin(), vect.end());

    int total_soldiers = 0;
    int current_soldiers = 0;

    for (int i = 0; i < n; ++i) {
        int ai = vect[i].first;
        int bi = vect[i].second;

        if (current_soldiers < ai) {
            total_soldiers += ai - current_soldiers;
            current_soldiers = ai;
        }
        current_soldiers -= bi;
    }
    std::cout << total_soldiers << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}