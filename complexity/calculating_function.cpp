#include <bits/stdc++.h>

void solve(){
    int64_t n;
    std::cin >> n;

    int64_t sum = n / 2;
    if(n % 2 != 0) {
        sum -= n;
    }

    std::cout << sum;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
