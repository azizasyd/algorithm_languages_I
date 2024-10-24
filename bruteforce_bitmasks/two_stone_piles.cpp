#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> w(n);
    long long sum_total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        sum_total += w[i];
    }

    long long min_diff = sum_total;
    long long best_mask = 0;

    for (long long mask = 0; mask < (1LL << n); ++mask) {
        long long sum_subset = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1LL << i)) {
                sum_subset += w[i];
            }
        }
        long long diff = abs(sum_total - 2 * sum_subset);
        if (diff < min_diff) {
            min_diff = diff;
            best_mask = mask;
            if (min_diff == 0) break;
        }
    }

    vector<int> indices;
    for (int i = 0; i < n; ++i) {
        if (best_mask & (1LL << i)) {
            indices.push_back(i + 1);
        }
    }

    cout << min_diff << "\n";
    cout << indices.size() << "\n";
    for (int idx : indices) {
        cout << idx << " ";
    }
    cout << "\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
