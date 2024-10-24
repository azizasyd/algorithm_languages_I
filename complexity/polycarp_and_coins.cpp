#include <bits/stdc++.h>

void solve(){
    int t; // 6
    std::cin >> t;

    while(t--){
        int64_t n; // 1000
        std::cin >> n;

        int64_t c2 = n / 3;
        int64_t c1 = n - 2 * c2;

        std::cout << c1 << " " << c2 << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}