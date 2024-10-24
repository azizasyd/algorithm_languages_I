#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> numbers(n);

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    vector<int> order(k);
    for (int i = 0; i < k; ++i) {
        order[i] = i;
    }

    auto calc = [&](vector<int>& order) {
        vector<int> res_numbers(n);
        for (int i = 0; i < n; ++i) {
            int number = 0;
            for (int j : order) {
                number *= 10;
                number += (numbers[i][j] - '0');
            }
            res_numbers[i] = number;
        }
        auto [min_it, max_it] = minmax_element(res_numbers.begin(), res_numbers.end());
        return *max_it - *min_it;
    };

    int ans = INT_MAX;

    do {
        int res = calc(order);
        ans = min(ans, res);
    } while (next_permutation(order.begin(), order.end()));

    cout << ans << "\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
