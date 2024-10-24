#include <bits/stdc++.h>

// NOT PASSED

//typedef long long ll;
using ll = long long;

void solve() {
    int n;
    ll s;
    std::cin >> n >> s;

    std::vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::unordered_map<ll, int> prefix_count;
    prefix_count[0] = 1;

    ll prefix_sum = 0;
    int result = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum += a[i];

        if (prefix_count.find(prefix_sum - s) != prefix_count.end()) {
            result += prefix_count[prefix_sum - s];
        }
        prefix_count[prefix_sum]++;
    }
    std::cout << result << "\n";

}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
