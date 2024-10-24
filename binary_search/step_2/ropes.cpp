#include <bits/stdc++.h>

using namespace std;

bool can_cut(const vector<double>& ropes, double length, int k) {
    int count = 0;
    for (double rope : ropes) {
        count += int(rope / length);
    }
    return count >= k;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<double> ropes(n);
    for (int i = 0; i < n; ++i) {
        cin >> ropes[i];
    }

    double left = 0.0, right = 1e7;
    for (int i = 0; i < 100; ++i) {
        double mid = (left + right) / 2;
        if (can_cut(ropes, mid, k)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << fixed << setprecision(1) << left << "\n";
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
