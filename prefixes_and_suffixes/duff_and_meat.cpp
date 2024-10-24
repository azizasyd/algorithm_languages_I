#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin >> n; // 3

    int opt_price = INT_MAX;
    int res = 0;
    std::vector<int> a(n), p(n);

    for(int i = 0; i < n; ++i){
        std::cin >> a[i] >> p[i];
        opt_price = std::min(opt_price, p[i]);
        res += a[i] * opt_price; // multiply by min price
    }
    std::cout << res << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
