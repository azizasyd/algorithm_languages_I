#include <bits/stdc++.h>

using namespace std;

bool can_gather(double time, const vector<pair<int, int>>& people) {
    double left = -1e18, right = 1e18;
    for (const auto& person : people) {
        double curr_left = person.first - time * person.second;
        double curr_right = person.first + time * person.second;
        left = max(left, curr_left);
        right = min(right, curr_right);
        if (left > right) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> people(n);
    for (int i = 0; i < n; ++i) {
        cin >> people[i].first >> people[i].second;
    }

    double left = 0, right = 1e18;
    for (int i = 0; i < 100; ++i) {
        double mid = (left + right) / 2;
        if (can_gather(mid, people)) {
            right = mid;
        } else {
            left = mid;
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